#include "Paint.h"
#include <math.h>
#include <vector>
#include "server.h"
#include <winuser.h>
#pragma comment (lib, "User32.lib")
#include "subCount.h"
#include "ExternalOverlay.h"
#include <tchar.h>


RECT passiveRect = { 64, 0, 128, 64 };
RECT activeRect = { 0, 0, 64, 64 };

LPD3DXSPRITE lmbSprite = NULL;
IDirect3DTexture9* lmbTexture = NULL;

LPD3DXSPRITE wSprite = NULL;
LPDIRECT3DTEXTURE9 wTexture = NULL;

LPD3DXSPRITE aSprite = NULL;
LPDIRECT3DTEXTURE9 aTexture = NULL;

LPD3DXSPRITE sSprite = NULL;
LPDIRECT3DTEXTURE9 sTexture = NULL;

LPD3DXSPRITE dSprite = NULL;
LPDIRECT3DTEXTURE9 dTexture = NULL;

int keystrokesInit(IDirect3DDevice9Ex* device)
{
    device ->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
    device->SetRenderState(D3DRS_BLENDOP, D3DBLENDOP_ADD);

    //creates texture
    D3DXCreateTextureFromFile(device, L"assests/lmb.png", &lmbTexture);

    D3DXCreateTextureFromFile(device, L"assests/wkey.png", &wTexture);
    D3DXCreateTextureFromFile(device, L"assests/akey.png", &aTexture);
    D3DXCreateTextureFromFile(device, L"assests/skey.png", &sTexture);
    D3DXCreateTextureFromFile(device, L"assests/dkey.png", &dTexture);



    //creates sprite interface
    D3DXCreateSprite(device, &lmbSprite);

    D3DXCreateSprite(device, &wSprite);
    D3DXCreateSprite(device, &aSprite);
    D3DXCreateSprite(device, &sSprite);
    D3DXCreateSprite(device, &dSprite);

    return 0;
}

int drawW(IDirect3DDevice9Ex* device, int width, int height)
{
    wSprite->Begin(NULL);

    if (GetKeyState(0x57) & 0x8000)
    {
        wSprite->Draw(wTexture, &activeRect, NULL, &D3DXVECTOR3(float(width * 0.955 - 70), float(height * 0.3 - 70), 0.0f), D3DCOLOR_ARGB(0, 255, 255, 255));
    }
    else {
        wSprite->Draw(wTexture, &passiveRect, NULL, &D3DXVECTOR3(float(width * 0.955 - 70), float(height * 0.3 - 70), 0.0f), D3DCOLOR_ARGB(0, 255, 255, 255));
    }

    wSprite->End();

    return 0;
}

int drawA(IDirect3DDevice9Ex* device, int width, int height)
{
    aSprite->Begin(NULL);
      
    if (GetKeyState(0x41) & 0x8000)
    {
        aSprite->Draw(aTexture, &activeRect, NULL, &D3DXVECTOR3(float(width * 0.955 - 140), float(height * 0.3), 0.0f), D3DCOLOR_ARGB(0, 255, 255, 255));
    }
    else {
        aSprite->Draw(aTexture, &passiveRect, NULL, &D3DXVECTOR3(float(width * 0.955 - 140), float(height * 0.3), 0.0f), D3DCOLOR_ARGB(0, 255, 255, 255));
    }

    aSprite->End();

    return 0;
}

int drawS(IDirect3DDevice9Ex* device, int width, int height)
{
    sSprite->Begin(NULL);

    if (GetKeyState(0x53) & 0x8000)
    {
        sSprite->Draw(sTexture, &activeRect, NULL, &D3DXVECTOR3(float(width * 0.955 - 70), float(height * 0.3), 0.0f), D3DCOLOR_ARGB(0, 255, 255, 255));
    }
    else {
        sSprite->Draw(sTexture, &passiveRect, NULL, &D3DXVECTOR3(float(width * 0.955 - 70), float(height * 0.3), 0.0f), D3DCOLOR_ARGB(0, 255, 255, 255));
    }

    sSprite->End();

    return 0;
}

int drawD(IDirect3DDevice9Ex* device, int width, int height)
{
    dSprite->Begin(NULL);

    if (GetKeyState(0x44) & 0x8000)
    {
        dSprite->Draw(dTexture, &activeRect, NULL, &D3DXVECTOR3(float(width * 0.955), float(height * 0.3), 0.0f), D3DCOLOR_ARGB(0, 255, 255, 255));
    }
    else {
        dSprite->Draw(dTexture, &passiveRect, NULL, &D3DXVECTOR3(float(width * 0.955), float(height * 0.3), 0.0f), D3DCOLOR_ARGB(0, 255, 255, 255));
    }

    dSprite->End();

    return 0;
}

int drawLMB(IDirect3DDevice9Ex* device, int width, int height)
{
    lmbSprite->Begin(NULL);

    if (GetKeyState(VK_LBUTTON) & 0x8000)
    {
        lmbSprite->Draw(lmbTexture, NULL, NULL, &D3DXVECTOR3(float(width * 0.955 - 140), float(height * 0.3 + 70), 0.0f), D3DCOLOR_ARGB(0, 255, 255, 255));
    }
    else {
        lmbSprite->Draw(lmbTexture, NULL, NULL, &D3DXVECTOR3(float(width * 0.955 - 140), float(height * 0.3 + 70), 0.0f), D3DCOLOR_ARGB(0, 255, 255, 255));
    }

    lmbSprite->End();

    return 0;
}

int drawKeystrokes(IDirect3DDevice9Ex* device, int width, int height)
{
    drawW(device, width, height);
    drawA(device, width, height);
    drawS(device, width, height);
    drawD(device, width, height);

    drawLMB(device, width, height);

    return 0;
}