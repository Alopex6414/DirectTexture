/*
*     COPYRIGHT NOTICE
*     Copyright(c) 2017, Team Shanghai Dream Equinox
*     All rights reserved.
*
* @file		DirectTexture.h
* @brief	This File is DirectTexture DLL Project.
* @author	Alopex/Helium
* @version	v1.00a
* @date		2017-12-10	v1.00a	alopex	Create This File
*/
#pragma once

#ifndef __DIRECTTEXTURE_H_
#define __DIRECTTEXTURE_H_

//Include DirectX Common Header File
#include "DirectCommon.h"

//Macro Definition
#ifdef	DIRECTTEXTURE_EXPORTS
#define DIRECTTEXTURE_API	__declspec(dllexport)
#else
#define DIRECTTEXTURE_API	__declspec(dllimport)
#endif

//Class Definition
class DIRECTTEXTURE_API DirectTexture
{
private:
	IDirect3DDevice9* m_pD3D9Device;			//The Direct3D 9 Device(D3D9�����豸)
	IDirect3DTexture9* m_pD3D9Texture;			//The Direct3D 9 Texture(D3D9��������)

public:
	DirectTexture();							//DirectTexture Constructor Function(���캯��)
	~DirectTexture();							//DirectTexture Destructor  Function(��������)

	//����
	DirectTexture(IDirect3DDevice9* pD3D9Device);							//DirectTexture Constructor Function(���캯��)(D3D9�����豸)

	//����
	IDirect3DDevice9* WINAPI DirectTextureGetDevice(void) const;			//DirectTexture Get D3D9 Device(��ȡD3D9�豸)
	IDirect3DTexture9* WINAPI DirectTextureGetTexture(void) const;			//DirectTexture Get D3D9 Texture(��ȡD3D9����)

	//����
	void WINAPI DirectTextureSetDevice(IDirect3DDevice9* pD3D9Device);		//DirectTexture Set D3D9 Device(����D3D9�豸)
	void WINAPI DirectTextureSetTexture(IDirect3DTexture9* pD3D9Texture);	//DirectTexture Set D3D9 Device(����D3D9����)

	//����
	virtual void WINAPI DirectTextureReset(void);							//DirectTexture Reset(����D3D9����)

	//��������
	virtual HRESULT WINAPI DirectTextureLoadTexture(LPWSTR lpszTexture);														//DirectTexture Load Texture(��������)(�ļ�)
	virtual HRESULT WINAPI DirectTextureLoadTexture(LPCVOID lpSrcData, UINT nSrcDataSize);										//DirectTexture Load Texture(��������)(�ڴ�)
	virtual HRESULT WINAPI DirectTextureLoadTextureEx(LPWSTR lpszTexture, UINT nWidth, UINT nHeight);							//DirectTexture Load Texture Ex(��������)(�ļ�)
	virtual HRESULT WINAPI DirectTextureLoadTextureEx(LPCVOID lpSrcData, UINT nSrcDataSize, UINT nWidth, UINT nHeight);			//DirectTexture Load Texture Ex(��������)(�ڴ�)

	//��Ⱦ����
	virtual void WINAPI DirectTextureSelectTexture(void);					//DirectTexture Select Texture(D3D9�豸ѡ������)

};


#endif