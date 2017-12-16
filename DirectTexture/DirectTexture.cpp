/*
*     COPYRIGHT NOTICE
*     Copyright(c) 2017, Team Shanghai Dream Equinox
*     All rights reserved.
*
* @file		DirectTexture.cpp
* @brief	This File is DirectTexture DLL Project.
* @author	Alopex/Helium
* @version	v1.00a
* @date		2017-12-10	v1.00a	alopex	Create This File
*/
#include "DirectCommon.h"
#include "DirectTexture.h"

//DirectTexture��Ҫ����2D/3D��������

//------------------------------------------------------------------
// @Function:	 DirectTexture()
// @Purpose: DirectTexture���캯��
// @Since: v1.00a
// @Para: None
// @Return: None
//------------------------------------------------------------------
DirectTexture::DirectTexture()
{
	m_pD3D9Device = NULL;		//IDirect3DDevice9�ӿ�ָ���ʼ��(NULL)
	m_pD3D9Texture = NULL;		//IDirect3DTexture9�ӿ�ָ���ʼ��(NULL)
}

//------------------------------------------------------------------
// @Function:	 ~DirectTexture()
// @Purpose: DirectTexture��������
// @Since: v1.00a
// @Para: None
// @Return: None
//------------------------------------------------------------------
DirectTexture::~DirectTexture()
{
	SAFE_RELEASE(m_pD3D9Texture);	//IDirect3DTexture9�ӿ�ָ���ͷ�
}

//------------------------------------------------------------------
// @Function:	 DirectTexture(IDirect3DDevice9* pD3D9Device)
// @Purpose: DirectTexture���캯��
// @Since: v1.00a
// @Para: IDirect3DDevice9* pD3D9Device	//D3D9�����豸
// @Return: None
//------------------------------------------------------------------
DirectTexture::DirectTexture(IDirect3DDevice9* pD3D9Device)
{
	m_pD3D9Device = pD3D9Device;		//IDirect3DDevice9�ӿ�ָ���ʼ��(NULL)
	m_pD3D9Texture = NULL;				//IDirect3DTexture9�ӿ�ָ���ʼ��(NULL)
}

//------------------------------------------------------------------
// @Function:	 DirectTextureGetDevice(void)
// @Purpose: DirectTexture��ȡD3D9�����豸
// @Since: v1.00a
// @Para: None
// @Return: None
//------------------------------------------------------------------
IDirect3DDevice9* WINAPI DirectTexture::DirectTextureGetDevice(void) const
{
	return m_pD3D9Device;
}

//------------------------------------------------------------------
// @Function:	 DirectTextureGetTexture(void)
// @Purpose: DirectTexture��ȡD3D9��������
// @Since: v1.00a
// @Para: None
// @Return: None
//------------------------------------------------------------------
IDirect3DTexture9* WINAPI DirectTexture::DirectTextureGetTexture(void) const
{
	return m_pD3D9Texture;
}

//------------------------------------------------------------------
// @Function:	 DirectTextureSetDevice(IDirect3DDevice9* pD3D9Device)
// @Purpose: DirectTexture����D3D9�����豸
// @Since: v1.00a
// @Para: IDirect3DDevice9* pD3D9Device	//D3D9�����豸
// @Return: None
//------------------------------------------------------------------
void WINAPI DirectTexture::DirectTextureSetDevice(IDirect3DDevice9* pD3D9Device)
{
	m_pD3D9Device = pD3D9Device;
}

//------------------------------------------------------------------
// @Function:	 DirectTextureSetTexture(IDirect3DTexture9* pD3D9Texture)
// @Purpose: DirectTexture����D3D9��������
// @Since: v1.00a
// @Para: IDirect3DTexture9* pD3D9Texture	//D3D9��������
// @Return: None
//------------------------------------------------------------------
void WINAPI DirectTexture::DirectTextureSetTexture(IDirect3DTexture9* pD3D9Texture)
{
	m_pD3D9Texture = m_pD3D9Texture;
}

//------------------------------------------------------------------
// @Function:	 DirectTextureReset(void)
// @Purpose: DirectTexture����D3D9��������
// @Since: v1.00a
// @Para: None
// @Return: None
//------------------------------------------------------------------
void WINAPI DirectTexture::DirectTextureReset(void)
{
	SAFE_RELEASE(m_pD3D9Texture);
}

//------------------------------------------------------------------
// @Function:	 DirectTextureLoadTexture(LPWSTR lpszTexture)
// @Purpose: DirectTexture��������
// @Since: v1.00a
// @Para: LPWSTR lpszTexture	//D3D9����·��
// @Return: None
//------------------------------------------------------------------
HRESULT WINAPI DirectTexture::DirectTextureLoadTexture(LPWSTR lpszTexture)
{
	VERIFY(D3DXCreateTextureFromFile(m_pD3D9Device, lpszTexture, &m_pD3D9Texture));

	return S_OK;
}

//-----------------------------------------------------------------------------
// @Function:	 DirectTextureLoadTexture(LPCVOID lpSrcData, UINT nSrcDataSize)
// @Purpose: DirectTexture��������
// @Since: v1.00a
// @Para: LPCVOID lpSrcData			//�����ڴ������ַ
// @Para: UINT nSrcDataSize			//�����ڴ������С
// @Return: None
//-----------------------------------------------------------------------------
HRESULT WINAPI DirectTexture::DirectTextureLoadTexture(LPCVOID lpSrcData, UINT nSrcDataSize)
{
	VERIFY(D3DXCreateTextureFromFileInMemory(m_pD3D9Device, lpSrcData, nSrcDataSize, &m_pD3D9Texture));

	return S_OK;
}

//----------------------------------------------------------------------------------------
// @Function:	 DirectTextureLoadTextureEx(LPWSTR lpszTexture, UINT nWidth, UINT nHeight)
// @Purpose: DirectTexture��������
// @Since: v1.00a
// @Para: LPWSTR lpszTexture	//D3D9����·��
// @Para: UINT nWidth			//��������(2^n)
// @Para: UINT nHeight			//�����߶�(2^n)
// @Return: None
//----------------------------------------------------------------------------------------
HRESULT WINAPI DirectTexture::DirectTextureLoadTextureEx(LPWSTR lpszTexture, UINT nWidth, UINT nHeight)
{
	VERIFY(D3DXCreateTextureFromFileEx(m_pD3D9Device, lpszTexture, nWidth, nHeight, 0, 0, D3DFMT_X8R8G8B8, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, D3DCOLOR_XRGB(0, 0, 0), NULL, NULL, &m_pD3D9Texture));

	return S_OK;
}

//----------------------------------------------------------------------------------------------------------
// @Function:	 DirectTextureLoadTextureEx(LPCVOID lpSrcData, UINT nSrcDataSize, UINT nWidth, UINT nHeight)
// @Purpose: DirectTexture��������
// @Since: v1.00a
// @Para: LPWSTR lpszTexture	//D3D9����·��
// @Para: UINT nWidth			//��������(2^n)
// @Para: UINT nHeight			//�����߶�(2^n)
// @Return: None
//----------------------------------------------------------------------------------------------------------
HRESULT WINAPI DirectTexture::DirectTextureLoadTextureEx(LPCVOID lpSrcData, UINT nSrcDataSize, UINT nWidth, UINT nHeight)
{
	VERIFY(D3DXCreateTextureFromFileInMemoryEx(m_pD3D9Device, lpSrcData, nSrcDataSize, nWidth, nHeight, 0, 0, D3DFMT_X8R8G8B8, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, D3DCOLOR_XRGB(0, 0, 0), NULL, NULL, &m_pD3D9Texture));
	
	return	S_OK;
}

//----------------------------------------------------------------------------------------------------------
// @Function:	 DirectTextureSelectTexture()
// @Purpose: DirectTexture��Ⱦ����
// @Since: v1.00a
// @Para: None
// @Return: None
//----------------------------------------------------------------------------------------------------------
void WINAPI DirectTexture::DirectTextureSelectTexture(void)
{
	m_pD3D9Device->SetTexture(0, m_pD3D9Texture);
}