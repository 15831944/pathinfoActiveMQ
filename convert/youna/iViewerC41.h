/**
* @date         2016-01-18
* @filename     iViewerC41.h
* @purpose      iViewer C interface for Henan province.
* @version      1.0
* @history      initial draft
* @author       Morgan Lei, UNIC, Beijing, China
* @copyright    Morgan.Lei@unic-tech.cn, UNIC Technologies Inc, 2005-2016. All rights reserved.
*/

#ifndef __IVIEWER_C_41_H__
#define __IVIEWER_C_41_H__

#ifdef IVIEWERC41_EXPORTS
#define IVIEWERC41_API __declspec(dllexport)
#else
#define IVIEWERC41_API __declspec(dllimport)
#endif

typedef long INT32;
typedef void* LPVOID;

#ifdef __cplusplus
extern "C" {
#endif

    typedef struct IMAGE_INFO_STRUCT
    {
        int DataFilePTR;
    } ImageInfoStruct;

    // ������
    // 1.sImageInfo����������ͼ���ļ�ָ��
    // 2.path������ͼ��·��
    IVIEWERC41_API bool InitImageFileFunc(ImageInfoStruct &sImageInfo, const char *Path);

    // ������
    // 1.sImageInfo����������ͼ���ļ�ָ��
    IVIEWERC41_API bool UnInitImageFileFunc(ImageInfoStruct &sImageInfo);

    // ������
    // 1.sImageInfo����������ͼ���ļ�ָ��
    // 2.fScale�����뱶��
    // 3.nImagePosX������X����
    // 4.nImagePosY������Y����
    // 5.nDataLength������ͼ�����ݳ���
    // 6.ImageStream������ͼ������ָ��
    // ��ע��ÿһ��ͼ���С������256*256
    IVIEWERC41_API unsigned char* GetImageStreamFunc(ImageInfoStruct &sImageInfo,
        float fScale,
        INT32 nImagePosX,
        INT32 nImagePosY,
        INT32 &nDataLength,
        unsigned char **ImageStream);

    // ������
    // 1.pImageData������ͼ������ָ��
    IVIEWERC41_API bool DeleteImageDataFunc(LPVOID pImageData);

    // ������
    // 1.szFilePath�����������ļ�·��
    // 2.ImageData������ͼ������ָ��
    // 3.nDataLength�����س���
    // 4.nThumWidth�����ؿ��
    // 5.nThumHeght�����ظ߶�
    IVIEWERC41_API bool GetThumnailImagePathFunc(const char *szFilePath,
        unsigned char **ImageData,
        INT32 &nDataLength,
        INT32 &nThumWidth,
        INT32 &nThumHeght);

    // ������
    // 1.szFilePath�����������ļ�·��
    // 2.ImageData������ͼ������ָ��
    // 3.nDataLength�����س���
    // 4.nPriviewWidth�����ؿ��
    // 5.nPriviewHeight�����ظ߶�
    IVIEWERC41_API bool GetPriviewInfoPathFunc(const char *szFilePath,
        unsigned char **ImageData,
        INT32 &nDataLength,
        INT32 &nPriviewWidth,
        INT32 &nPriviewHeight);

    // ������
    // 1.szFilePath�����������ļ�·��
    // 2.ImageData������ͼ������ָ��
    // 3.nDataLength�����س���
    // 4.nLabelWidth�����ؿ��
    // 5.nLabelHeight�����ظ߶�
    IVIEWERC41_API bool GetLableInfoPathFunc(const char *szFilePath,
        unsigned char **ImageData,
        INT32 &nDataLength,
        INT32 &nLabelWidth,
        INT32 &nLabelHeight);

    // ������
    // 1.ImageInfo������ͼ������ָ��
    // 2.khiImageHeight������ɨ��߶�
    // 3.khiImageWidth������ɨ����
    // 4.khiScanScale������ɨ�豶��
    // 5.khiSpendTime������ɨ��ʱ��
    // 6.khiImageCapRes������ͼ�����
    // 7.khiImageBlockSize������ͼ����С
    IVIEWERC41_API bool GetHeaderInfoFunc(ImageInfoStruct sImageInfo,
        long &khiImageHeight,
        long &khiImageWidth,
        long &khiScanScale,
        float &khiSpendTime,
        double &khiScanTime,	
        float &khiImageCapRes, 
        long &khiImageBlockSize);

    // ����
    // 1.ImageInfo������ͼ������ָ��
    // 2.fScale�����뱶��
    // 3.sp_x�����Ͻ�X����
    // 4.sp_y�����Ͻ�Y����
    // 5.nWidth�����
    // 6.nHeight���߶�
    // 7.pBuffer������ͼ������ָ��
    // 8.DataLength������ͼ���ֽڳ���
    // 9.flag��true
    IVIEWERC41_API bool GetImageDataRoiFunc(ImageInfoStruct sImageInfo,
        float fScale,
        INT32 sp_x,
        INT32 sp_y,
        INT32 nWidth,
        INT32 nHeight,
        unsigned char **pBuffer,
        INT32 &DataLength,
        bool flag);

#ifdef __cplusplus
};
#endif

#endif // __IVIEWER_C_41_H__
