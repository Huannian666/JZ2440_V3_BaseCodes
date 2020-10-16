
#ifndef _FONTS_MANAGER_H
#define _FONTS_MANAGER_H

typedef struct FontBitMap {
    int iXLeft;  /* 位图左上角X座标 */
    int iYTop;   /* 位图左上角Y座标 */
    int iXMax;   /* 位图的最大X座标值 */
    int iYMax;   /* 位图的最大Y座标值 */
    int iBpp;    /* 位图中一个象素用多少位来表示 */
    int iPitch;  /* 对于单色位图, 两行象素之间的跨度, 即第N行、第N+1行象素数据之间的偏移值 */
    int iCurOriginX;  /* 位图的原点X座标(一般是左下角), 使用原点来确定相邻字符的位置 */
    int iCurOriginY;  /* 位图的原点Y座标 */
    int iNextOriginX; /* 下一个字符即右边字符的原点X座标 */
    int iNextOriginY; /* 下一个字符即右边字符的原点Y座标 */
    unsigned char *pucBuffer;  /* 存有字符的位图数据 */
}T_FontBitMap, *PT_FontBitMap;

typedef struct FontOpr {
    char *name;             /* 字体模块的名字 */
    int (*FontInit)(char *pcFontFile, unsigned int dwFontSize);  /* 字体模块的初始化函数 */
    int (*GetFontBitmap)(unsigned int dwCode, PT_FontBitMap ptFontBitMap);  /* 根据编码值获得字符的位图 */
    void (*SetFontSize)(unsigned int dwFontSize);   /* 设置字体尺寸(单位:象素) */
    struct FontOpr *ptNext;  /* 链表 */
}T_FontOpr, *PT_FontOpr;


/**********************************************************************
 * 函数名称： RegisterFontOpr
 * 功能描述： 注册"字体模块", 所谓字体模块就是取出字符位图的方法
 * 输入参数： ptFontOpr - 一个结构体,内含"取出字符位图"的操作函数
 * 输出参数： 无
 * 返 回 值： 0 - 成功, 其他值 - 失败
 * 修改日期        版本号     修改人          修改内容
 * -----------------------------------------------
 * 2013/02/08         V1.0      韦东山          创建
 ***********************************************************************/
int RegisterFontOpr(PT_FontOpr ptFontOpr);

/**********************************************************************
 * 函数名称： ShowFontOpr
 * 功能描述： 显示本程序能支持的"字体模块"
 * 输入参数： 无
 * 输出参数： 无
 * 返 回 值： 无
 * 修改日期        版本号     修改人          修改内容
 * -----------------------------------------------
 * 2013/02/08         V1.0      韦东山          创建
 ***********************************************************************/
void ShowFontOpr(void);

/**********************************************************************
 * 函数名称： FontsInit
 * 功能描述： 调用各个字体模块的初始化函数
 * 输入参数： 无
 * 输出参数： 无
 * 返 回 值： 0 - 成功, 其他值 - 失败
 * 修改日期        版本号     修改人          修改内容
 * -----------------------------------------------
 * 2013/02/08         V1.0      韦东山          创建
 ***********************************************************************/
int FontsInit(void);

/**********************************************************************
 * 函数名称： ASCIIInit
 * 功能描述： 注册"ASCII字体模块"
 * 输入参数： 无
 * 输出参数： 无
 * 返 回 值： 0 - 成功, 其他值 - 失败
 * 修改日期        版本号     修改人          修改内容
 * -----------------------------------------------
 * 2013/02/08         V1.0      韦东山          创建
 ***********************************************************************/
int ASCIIInit(void);

/**********************************************************************
 * 函数名称： GBKInit
 * 功能描述： 注册"GBK字体模块"
 * 输入参数： 无
 * 输出参数： 无
 * 返 回 值： 0 - 成功, 其他值 - 失败
 * 修改日期        版本号     修改人          修改内容
 * -----------------------------------------------
 * 2013/02/08         V1.0      韦东山          创建
 ***********************************************************************/
int GBKInit(void);

/**********************************************************************
 * 函数名称： FreeTypeInit
 * 功能描述： 注册"FreeType字体模块"
 * 输入参数： 无
 * 输出参数： 无
 * 返 回 值： 0 - 成功, 其他值 - 失败
 * 修改日期        版本号     修改人          修改内容
 * -----------------------------------------------
 * 2013/02/08         V1.0      韦东山          创建
 ***********************************************************************/
int FreeTypeInit(void);

/**********************************************************************
 * 函数名称： GetFontOpr
 * 功能描述： 根据名字取出指定的"字体模块"
 * 输入参数： pcName - 名字
 * 输出参数： 无
 * 返 回 值： NULL   - 失败,没有指定的模块, 
 *            非NULL - 字体模块的PT_FontOpr结构体指针
 * 修改日期        版本号     修改人          修改内容
 * -----------------------------------------------
 * 2013/02/08         V1.0      韦东山          创建
 ***********************************************************************/
PT_FontOpr GetFontOpr(char *pcName);

/**********************************************************************
 * 函数名称： SetFontSize
 * 功能描述： 设置字符的尺寸(单位:色素)
 * 输入参数： dwFontSize - 字符的尺寸(单位:色素)
 * 输出参数： 无
 * 返 回 值： 无
 * 修改日期        版本号     修改人          修改内容
 * -----------------------------------------------
 * 2013/02/08         V1.0      韦东山          创建
 ***********************************************************************/
void SetFontSize(unsigned int dwFontSize);

/**********************************************************************
 * 函数名称： GetFontSize
 * 功能描述： 获得字符的尺寸(单位:色素)
 * 输入参数： 无
 * 输出参数： 无
 * 返 回 值： 字符的尺寸(单位:色素)
 * 修改日期        版本号     修改人          修改内容
 * -----------------------------------------------
 * 2013/02/08         V1.0      韦东山          创建
 ***********************************************************************/
unsigned int GetFontSize(void);

/**********************************************************************
 * 函数名称： GetFontBitmap
 * 功能描述： 获得字符的位图
 * 输入参数： dwCode       - 字符的编码值(可能是ASCII/GBK/UNICODE)
 * 输出参数： ptFontBitMap - 内含位图信息
 * 返 回 值： 0  - 成功
 *            -1 - 失败 
 * 修改日期        版本号     修改人          修改内容
 * -----------------------------------------------
 * 2013/02/08         V1.0      韦东山          创建
 ***********************************************************************/
int GetFontBitmap(unsigned int dwCode, PT_FontBitMap ptFontBitMap);

/**********************************************************************
 * 函数名称： SetFontsDetail
 * 功能描述： 设置字体模块的信息,比如指定字库文件,指定字符尺寸
 * 输入参数： pcFontsName - 要设置的字体模块的名字
 *            pcFontsFile - 字库文件
 *            dwFontSize  - 字符的尺寸(单位:色素), 程序运行时可用SetFontSize修改
 * 输出参数： 无
 * 返 回 值： 0      - 成功
 *            其他值 - 失败 
 * 修改日期        版本号     修改人          修改内容
 * -----------------------------------------------
 * 2013/02/08         V1.0      韦东山          创建
 ***********************************************************************/
int SetFontsDetail(char *pcFontsName, char *pcFontsFile, unsigned int dwFontSize);

#endif /* _FONTS_MANAGER_H */

