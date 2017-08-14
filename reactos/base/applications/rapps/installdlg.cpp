/*
 * PROJECT:         ReactOS Applications Manager
 * LICENSE:         GPL - See COPYING in the top level directory
 * FILE:            base/applications/rapps/installdlg.cpp
 * PURPOSE:         "Download and Install" Dialog
 * PROGRAMMERS:     Dmitry Chapyshev (dmitry@reactos.org)
 */
#include "defines.h"

#include "dialogs.h"
#include "available.h"

static PAPPLICATION_INFO AppInfo;

static
INT_PTR CALLBACK
InstallDlgProc(HWND hDlg, UINT Msg, WPARAM wParam, LPARAM lParam)
{
    switch (Msg)
    {
        case WM_INITDIALOG:
        {
        }
        break;

        case WM_COMMAND:
        {
            switch (LOWORD(wParam))
            {
                case IDOK:
                case IDCANCEL:
                    EndDialog(hDlg, LOWORD(wParam));
                break;
            }
        }
        break;
    }

    return FALSE;
}

BOOL
InstallApplication(INT Index)
{
    if (!isAvailableEnum(SelectedEnumType))
        return FALSE;

    AppInfo = (PAPPLICATION_INFO) ListViewGetlParam(Index);
    if (!AppInfo) return FALSE;

    DialogBoxW(hInst,
              MAKEINTRESOURCEW(IDD_INSTALL_DIALOG),
              hMainWnd,
              InstallDlgProc);

    return TRUE;
}