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
	IDirect3DDevice9* m_pD3D9Device;			//The Direct3D 9 Device(D3D9绘制设备)
	IDirect3DTexture9* m_pD3D9Texture;			//The Direct3D 9 Texture(D3D9绘制纹理)

public:
	DirectTexture();							//DirectTexture Constructor Function(构造函数)
	~DirectTexture();							//DirectTexture Destructor  Function(析构函数)

	//构造
	DirectTexture(IDirect3DDevice9* pD3D9Device);							//DirectTexture Constructor Function(构造函数)(D3D9绘制设备)

	//访问
	IDirect3DDevice9* WINAPI DirectTextureGetDevice(void) const;			//DirectTexture Get D3D9 Device(获取D3D9设备)
	IDirect3DTexture9* WINAPI DirectTextureGetTexture(void) const;			//DirectTexture Get D3D9 Texture(获取D3D9纹理)

	//控制
	void WINAPI DirectTextureSetDevice(IDirect3DDevice9* pD3D9Device);		//DirectTexture Set D3D9 Device(设置D3D9设备)
	void WINAPI DirectTextureSetTexture(IDirect3DTexture9* pD3D9Texture);	//DirectTexture Set D3D9 Device(设置D3D9纹理)

	//重置
	virtual void WINAPI DirectTextureReset(void);							//DirectTexture Reset(重置D3D9纹理)

	//加载纹理
	virtual HRESULT WINAPI DirectTextureLoadTexture(LPWSTR lpszTexture);														//DirectTexture Load Texture(加载纹理)(文件)
	virtual HRESULT WINAPI DirectTextureLoadTexture(LPCVOID lpSrcData, UINT nSrcDataSize);										//DirectTexture Load Texture(加载纹理)(内存)
	virtual HRESULT WINAPI DirectTextureLoadTextureEx(LPWSTR lpszTexture, UINT nWidth, UINT nHeight);							//DirectTexture Load Texture Ex(加载纹理)(文件)
	virtual HRESULT WINAPI DirectTextureLoadTextureEx(LPCVOID lpSrcData, UINT nSrcDataSize, UINT nWidth, UINT nHeight);			//DirectTexture Load Texture Ex(加载纹理)(内存)

	//渲染纹理
	virtual void WINAPI DirectTextureSelectTexture(void);					//DirectTexture Select Texture(D3D9设备选中纹理)

};


#endif