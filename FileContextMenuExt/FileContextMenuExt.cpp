/****************************** Module Header ******************************\
Module Name:  FileContextMenuExt.cpp
Project:      CppShellExtContextMenuHandler
Copyright (c) Microsoft Corporation.

The code sample demonstrates creating a Shell context menu handler with C++. 

A context menu handler is a shell extension handler that adds commands to an 
existing context menu. Context menu handlers are associated with a particular 
file class and are called any time a context menu is displayed for a member 
of the class. While you can add items to a file class context menu with the 
registry, the items will be the same for all members of the class. By 
implementing and registering such a handler, you can dynamically add items to 
an object's context menu, customized for the particular object.

The example context menu handler adds the menu item "Display File Name (C++)"
to the context menu when you right-click a .cpp file in the Windows Explorer. 
Clicking the menu item brings up a message box that displays the full path 
of the .cpp file.

This source is subject to the Microsoft Public License.
See http://www.microsoft.com/opensource/licenses.mspx#Ms-PL.
All other rights reserved.

THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, 
EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED 
WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
\***************************************************************************/

#include "FileContextMenuExt.h"
#include <strsafe.h>
#include <Shlwapi.h>
#pragma comment(lib, "shlwapi.lib")

#define IDM_DISPLAY             0  // The command's identifier offset

FileContextMenuExt::FileContextMenuExt(void) : m_cRef(1), 
    m_pszMenuText(L"&Avid the Best"),
    m_pszVerb("cppdisplay"),
    m_pwszVerb(L"cppdisplay"),
    m_pszVerbCanonicalName("CppDisplayFileName"),
    m_pwszVerbCanonicalName(L"CppDisplayFileName"),
    m_pszVerbHelpText("Avid the Best"),
    m_pwszVerbHelpText(L"Avid the Best")
{
}

FileContextMenuExt::~FileContextMenuExt(void)
{
}

// comparison, not case sensitive.
bool compare_nocase (std::wstring first, std::wstring second)
{
  unsigned int i=0;
  while ( (i<first.length()) && (i<second.length()) )
  {
    if (tolower(first[i])<tolower(second[i])) return true;
    else if (tolower(first[i])>tolower(second[i])) return false;
    ++i;
  }
  if (first.length()<second.length()) return true;
  else return false;

  //return (wcscmp(first.data(), second.data())) ? true : false;
  //return ((first.data() < second.data()) ? true : false);
}

DWORD GetCheckSum(const HANDLE hFile, DWORD fileSize)
{
	char readBuffer = 0;
	DWORD numberOfBytesToRead = sizeof readBuffer;
	DWORD numberOfBytesRead;
	DWORD checkSum = 0;

	for (DWORD i = 0; i < fileSize; ++i)
	{
		readBuffer = 0;

		ReadFile(hFile,
                 &readBuffer,
                 numberOfBytesToRead,
                 &numberOfBytesRead,
                 NULL);

		checkSum ^= readBuffer;
	}

	return checkSum;
}

struct threadParams
{
	std::wstring inFileName;
	std::wstring result;
	bool completed;
};

void GetCheckSumThread(void *dummy)
{
    threadParams *params = (threadParams*)(dummy);

	std::wstring inFileNameShort = params->inFileName;
	std::wstring::size_type index = inFileNameShort.find_last_of(L"\\");
	inFileNameShort.erase(0, index + 1);

	HANDLE hInFile = CreateFile(params->inFileName.data(),
                                GENERIC_READ,
                                FILE_SHARE_READ,
                                NULL,
                                OPEN_EXISTING,
                                FILE_ATTRIBUTE_NORMAL,
                                NULL);

	if (INVALID_HANDLE_VALUE != hInFile)
	{
		DWORD fileSize = GetFileSize(hInFile,
                                     NULL);

		const wchar_t *units[] = {L"B", L"KB", L"MB", L"GB", L"TB", L"PB", L"EB", L"ZB", L"YB"};
		wchar_t strFileSize[100] = L"";
		double size = fileSize;
		int i = 0;
		
		while (size > 1024)
		{
			size /= 1024;
			++i;
		}

		swprintf(strFileSize, L"%.*f %s", i, size, units[i]);

		FILETIME lCreationTime;
		GetFileTime(hInFile,
					&lCreationTime,
					NULL,
					NULL);

		SYSTEMTIME lSystemTime, lLocalTime;
		FileTimeToSystemTime(&lCreationTime,
							 &lSystemTime);

		SystemTimeToTzSpecificLocalTime(NULL,
										&lSystemTime,
										&lLocalTime);

		DWORD checkSum = GetCheckSum(hInFile,
									 fileSize);

		wchar_t strResult[1000] = L"";
		swprintf(strResult,
				 L"%s\t%s\t%02d.%02d.%04d %02d:%02d:%02d\t%u",
				 inFileNameShort.data(),
				 strFileSize,
				 lLocalTime.wDay, lLocalTime.wMonth, lLocalTime.wYear,
				 lLocalTime.wHour, lLocalTime.wMinute, lLocalTime.wSecond,
				 checkSum);

		params->result = strResult;
		params->completed = true;

		CloseHandle(hInFile);
	}
	else
	{
		params->result = inFileNameShort.data();
		params->result += L"\tACCESS_DENIED";
		params->completed = true;
	}
}

void FileContextMenuExt::OnVerbDisplayFileName(HWND hWnd)
{
    //wchar_t szMessage[300];
    //if (SUCCEEDED(StringCchPrintf(szMessage, ARRAYSIZE(szMessage), 
    //    L"The selected file is:\r\n\r\n%s", this->m_szSelectedFile)))
    //{
    //    MessageBox(hWnd, szMessage, L"CppShellExtContextMenuHandler", MB_OK);
    //}

	DWORD startTime = GetTickCount();

	std::wstring outFileName = *selectedFiles.begin();
	std::wstring::size_type index = outFileName.find_last_of(L"\\");
	outFileName.replace(index, outFileName.length() - index, L"\\FileContextMenuExt_out.txt");

	HANDLE hOutFile = CreateFile(outFileName.data(),
                                 GENERIC_WRITE,
                                 FILE_SHARE_WRITE | FILE_SHARE_READ,
                                 NULL,
                                 CREATE_ALWAYS,
                                 FILE_ATTRIBUTE_NORMAL,
                                 NULL);

	if (INVALID_HANDLE_VALUE != hOutFile)
	{
		DWORD threadsCount = 0L;

		std::list<std::wstring>::iterator iter,begin,begin10,end,end10;
		begin10 = begin = selectedFiles.begin();
		end10 = end = selectedFiles.end();

		threadParams *params = new threadParams[selectedFiles.size()];
		
		for (iter = begin; iter != end; iter++)
		{
			params[threadsCount].inFileName = *iter;
			params[threadsCount].result = L"";
			params[threadsCount].completed = false;

			_beginthread(GetCheckSumThread, 0, (void*)(&params[threadsCount]));

			++threadsCount;
		}

		std::wstring Message = L"The selected files are:\r\n\r\n";
		
		for (DWORD i = 0L; i < threadsCount; )
		{
			if (!params[i].completed)
			{
				continue;
			}

			std::wstring outBuffer = params[i].result;
			outBuffer += L"\r\n";

			DWORD dwBytesWritten = 0L;
			WriteFile(hOutFile,
					  outBuffer.data(),
					  outBuffer.length() * sizeof(wchar_t),
					  &dwBytesWritten,
					  NULL);

			bool showThisItem = false;

			if (selectedFiles.size() < 21)
			{
				showThisItem = true;
			}
			else
			{
				if ((i < 10) || (i >= (selectedFiles.size() - 10)))
				{
					showThisItem = true;
				}
				else if (i == 10)
				{
					Message += L"...\r\n";
				}
			}

			if (showThisItem)
			{
				Message += outBuffer.data();
			}

			++i;
		}

		DWORD endTime = GetTickCount();
		DWORD spentTime = endTime - startTime;
		DWORD msec = spentTime % 1000;
		DWORD sec = spentTime / 1000;
		DWORD min = spentTime / 60000;

		wchar_t spentTimeBuffer[100] = L"";
		swprintf(spentTimeBuffer, L"\r\nSpent time: %02d:%02d.%03d", min, sec, msec);
		Message += spentTimeBuffer;

		MessageBox(hWnd, Message.data(), L"CppShellExtContextMenuHandler", MB_OK);

		delete[] params;
		CloseHandle(hOutFile);
	}
	else
	{
		MessageBox(hWnd, L"Can't open FileContextMenuExt_out.txt for writing!!!", L"CppShellExtContextMenuHandler", MB_OK);
	}
}


#pragma region IUnknown

// Query to the interface the component supported.
IFACEMETHODIMP FileContextMenuExt::QueryInterface(REFIID riid, void **ppv)
{
    HRESULT hr = S_OK;

    if (IsEqualIID(IID_IUnknown, riid) || 
        IsEqualIID(IID_IContextMenu, riid))
    {
        *ppv = static_cast<IContextMenu *>(this);
    }
    else if (IsEqualIID(IID_IShellExtInit, riid))
    {
        *ppv = static_cast<IShellExtInit *>(this);
    }
    else
    {
        hr = E_NOINTERFACE;
        *ppv = NULL;
    }

    if (*ppv)
    {
        AddRef();
    }

    return hr;
}

// Increase the reference count for an interface on an object.
IFACEMETHODIMP_(ULONG) FileContextMenuExt::AddRef()
{
    return InterlockedIncrement(&m_cRef);
}

// Decrease the reference count for an interface on an object.
IFACEMETHODIMP_(ULONG) FileContextMenuExt::Release()
{
    ULONG cRef = InterlockedDecrement(&m_cRef);
    if (0 == cRef)
    {
        delete this;
    }

    return cRef;
}

#pragma endregion

#pragma region IShellExtInit

// Initialize the context menu handler.
IFACEMETHODIMP FileContextMenuExt::Initialize(
    LPCITEMIDLIST pidlFolder, LPDATAOBJECT pDataObj, HKEY hKeyProgID)
{
    if (NULL == pDataObj)
    {
        return E_INVALIDARG;
    }

    HRESULT hr = E_FAIL;

    FORMATETC fe = { CF_HDROP, NULL, DVASPECT_CONTENT, -1, TYMED_HGLOBAL };
    STGMEDIUM stm;

    // The pDataObj pointer contains the objects being acted upon. In this 
    // example, we get an HDROP handle for enumerating the selected files and 
    // folders.
    if (SUCCEEDED(pDataObj->GetData(&fe, &stm)))
    {
        // Get an HDROP handle.
        HDROP hDrop = static_cast<HDROP>(GlobalLock(stm.hGlobal));
        if (hDrop != NULL)
        {
            // Determine how many files are involved in this operation. This 
            // code sample displays the custom context menu item when only 
            // one file is selected. 
            UINT nFiles = DragQueryFile(hDrop, 0xFFFFFFFF, NULL, 0);
            //if (nFiles == 1)
            //{
            //    // Get the path of the file.
            //    if (0 != DragQueryFile(hDrop, 0, m_szSelectedFile, 
            //        ARRAYSIZE(m_szSelectedFile)))
            //    {
            //        hr = S_OK;
            //    }
            //}

			if (nFiles > 0)
			{
				wchar_t szFileName[MAX_PATH];
				for (UINT i = 0; i < nFiles; i++)
				{
					if (0 != DragQueryFile(hDrop, i, szFileName, ARRAYSIZE(szFileName)))
					{
						if (FILE_ATTRIBUTE_DIRECTORY != GetFileAttributes(szFileName))
						{
							selectedFiles.push_back(szFileName);
						}
					}
				}

				if (selectedFiles.size() > 0)
				{
					selectedFiles.sort(compare_nocase);
					hr = S_OK;
				}
			}

            // [-or-]

            // Enumerates the selected files and folders.
            //if (nFiles > 0)
            //{
            //    std::list<std::wstring> selectedFiles;
            //    wchar_t szFileName[MAX_PATH];
            //    for (UINT i = 0; i < nFiles; i++)
            //    {
            //        // Get the next file name.
            //        if (0 != DragQueryFile(hDrop, i, szFileName, ARRAYSIZE(szFileName)))
            //        {
            //            // Add the file name to the list.
            //            selectedFiles.push_back(szFileName);
            //        }
            //    }

            //    // If we found any files we can work with, return S_OK.
            //    if (selectedFiles.size() > 0) 
            //    {
            //        hr = S_OK;
            //    }
            //}

            GlobalUnlock(stm.hGlobal);
        }

        ReleaseStgMedium(&stm);
    }

    // If any value other than S_OK is returned from the method, the context 
    // menu item is not displayed.
    return hr;
}

#pragma endregion


#pragma region IContextMenu

//
//   FUNCTION: FileContextMenuExt::QueryContextMenu
//
//   PURPOSE: The Shell calls IContextMenu::QueryContextMenu to allow the 
//            context menu handler to add its menu items to the menu. It 
//            passes in the HMENU handle in the hmenu parameter. The 
//            indexMenu parameter is set to the index to be used for the 
//            first menu item that is to be added.
//
IFACEMETHODIMP FileContextMenuExt::QueryContextMenu(
    HMENU hMenu, UINT indexMenu, UINT idCmdFirst, UINT idCmdLast, UINT uFlags)
{
    // If uFlags include CMF_DEFAULTONLY then we should not do anything.
    if (CMF_DEFAULTONLY & uFlags)
    {
        return MAKE_HRESULT(SEVERITY_SUCCESS, 0, USHORT(0));
    }

    // Use either InsertMenu or InsertMenuItem to add menu items.
    // Learn how to add sub-menu from:
    // http://www.codeproject.com/KB/shell/ctxextsubmenu.aspx

    MENUITEMINFO mii = { sizeof(mii) };
    mii.fMask = MIIM_ID | MIIM_TYPE | MIIM_STATE;
    mii.wID = idCmdFirst + IDM_DISPLAY;
    mii.fType = MFT_STRING;
    mii.dwTypeData = m_pszMenuText;
    mii.fState = MFS_ENABLED;
    if (!InsertMenuItem(hMenu, indexMenu, TRUE, &mii))
    {
        return HRESULT_FROM_WIN32(GetLastError());
    }

    // Add a separator.
    MENUITEMINFO sep = { sizeof(sep) };
    sep.fMask = MIIM_TYPE;
    sep.fType = MFT_SEPARATOR;
    if (!InsertMenuItem(hMenu, indexMenu + 1, TRUE, &sep))
    {
        return HRESULT_FROM_WIN32(GetLastError());
    }

    // Return an HRESULT value with the severity set to SEVERITY_SUCCESS. 
    // Set the code value to the offset of the largest command identifier 
    // that was assigned, plus one (1).
    return MAKE_HRESULT(SEVERITY_SUCCESS, 0, USHORT(IDM_DISPLAY + 1));
}


//
//   FUNCTION: FileContextMenuExt::InvokeCommand
//
//   PURPOSE: This method is called when a user clicks a menu item to tell 
//            the handler to run the associated command. The lpcmi parameter 
//            points to a structure that contains the needed information.
//
IFACEMETHODIMP FileContextMenuExt::InvokeCommand(LPCMINVOKECOMMANDINFO pici)
{
    BOOL fUnicode = FALSE;

    // Determine which structure is being passed in, CMINVOKECOMMANDINFO or 
    // CMINVOKECOMMANDINFOEX based on the cbSize member of lpcmi. Although 
    // the lpcmi parameter is declared in Shlobj.h as a CMINVOKECOMMANDINFO 
    // structure, in practice it often points to a CMINVOKECOMMANDINFOEX 
    // structure. This struct is an extended version of CMINVOKECOMMANDINFO 
    // and has additional members that allow Unicode strings to be passed.
    if (pici->cbSize == sizeof(CMINVOKECOMMANDINFOEX))
    {
        if (pici->fMask & CMIC_MASK_UNICODE)
        {
            fUnicode = TRUE;
        }
    }

    // Determines whether the command is identified by its offset or verb.
    // There are two ways to identify commands:
    // 
    //   1) The command's verb string 
    //   2) The command's identifier offset
    // 
    // If the high-order word of lpcmi->lpVerb (for the ANSI case) or 
    // lpcmi->lpVerbW (for the Unicode case) is nonzero, lpVerb or lpVerbW 
    // holds a verb string. If the high-order word is zero, the command 
    // offset is in the low-order word of lpcmi->lpVerb.

    // For the ANSI case, if the high-order word is not zero, the command's 
    // verb string is in lpcmi->lpVerb. 
    if (!fUnicode && HIWORD(pici->lpVerb))
    {
        // Is the verb supported by this context menu extension?
        if (StrCmpIA(pici->lpVerb, m_pszVerb) == 0)
        {
            OnVerbDisplayFileName(pici->hwnd);
        }
        else
        {
            // If the verb is not recognized by the context menu handler, it 
            // must return E_FAIL to allow it to be passed on to the other 
            // context menu handlers that might implement that verb.
            return E_FAIL;
        }
    }

    // For the Unicode case, if the high-order word is not zero, the 
    // command's verb string is in lpcmi->lpVerbW. 
    else if (fUnicode && HIWORD(((CMINVOKECOMMANDINFOEX*)pici)->lpVerbW))
    {
        // Is the verb supported by this context menu extension?
        if (StrCmpIW(((CMINVOKECOMMANDINFOEX*)pici)->lpVerbW, m_pwszVerb) == 0)
        {
            OnVerbDisplayFileName(pici->hwnd);
        }
        else
        {
            // If the verb is not recognized by the context menu handler, it 
            // must return E_FAIL to allow it to be passed on to the other 
            // context menu handlers that might implement that verb.
            return E_FAIL;
        }
    }

    // If the command cannot be identified through the verb string, then 
    // check the identifier offset.
    else
    {
        // Is the command identifier offset supported by this context menu 
        // extension?
        if (LOWORD(pici->lpVerb) == IDM_DISPLAY)
        {
            OnVerbDisplayFileName(pici->hwnd);
        }
        else
        {
            // If the verb is not recognized by the context menu handler, it 
            // must return E_FAIL to allow it to be passed on to the other 
            // context menu handlers that might implement that verb.
            return E_FAIL;
        }
    }

    return S_OK;
}


//
//   FUNCTION: CFileContextMenuExt::GetCommandString
//
//   PURPOSE: If a user highlights one of the items added by a context menu 
//            handler, the handler's IContextMenu::GetCommandString method is 
//            called to request a Help text string that will be displayed on 
//            the Windows Explorer status bar. This method can also be called 
//            to request the verb string that is assigned to a command. 
//            Either ANSI or Unicode verb strings can be requested. This 
//            example only implements support for the Unicode values of 
//            uFlags, because only those have been used in Windows Explorer 
//            since Windows 2000.
//
IFACEMETHODIMP FileContextMenuExt::GetCommandString(UINT_PTR idCommand, 
    UINT uFlags, UINT *pwReserved, LPSTR pszName, UINT cchMax)
{
    HRESULT hr = E_INVALIDARG;

    if (idCommand == IDM_DISPLAY)
    {
        switch (uFlags)
        {
        case GCS_HELPTEXTW:
            // Only useful for pre-Vista versions of Windows that have a 
            // Status bar.
            hr = StringCchCopy(reinterpret_cast<PWSTR>(pszName), cchMax, 
                m_pwszVerbHelpText);
            break;

        case GCS_VERBW:
            // GCS_VERBW is an optional feature that enables a caller to 
            // discover the canonical name for the verb passed in through 
            // idCommand.
            hr = StringCchCopy(reinterpret_cast<PWSTR>(pszName), cchMax, 
                m_pwszVerbCanonicalName);
            break;

        default:
            hr = S_OK;
        }
    }

    // If the command (idCommand) is not supported by this context menu 
    // extension handler, return E_INVALIDARG.

    return hr;
}

#pragma endregion