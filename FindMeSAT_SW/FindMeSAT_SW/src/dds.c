/**
 * \file
 *
 * \brief FindMeSAT
 * dds.c
 *
 * Created: 04.07.2017 14:59:47
 * Author : DF4IAH
 *
 */

/*
 * Include header files for all drivers that have been imported from
 * Atmel Software Framework (ASF).
 */
/*
 * Support and FAQ: visit <a href="http://www.atmel.com/design-support/">Atmel Support</a>
 */
#include <asf.h>

#include "dds.h"


/* 4k points sine ROM table */

uint16_t PROGMEM_T PM_SINE[PM_SINE_COUNT] = {
	0x8000, 0x8032, 0x8064, 0x8096, 0x80c9, 0x80fb, 0x812d, 0x815f,
	0x8192, 0x81c4, 0x81f6, 0x8228, 0x825b, 0x828d, 0x82bf, 0x82f1,
	0x8324, 0x8356, 0x8388, 0x83ba, 0x83ed, 0x841f, 0x8451, 0x8483,
	0x84b6, 0x84e8, 0x851a, 0x854c, 0x857e, 0x85b1, 0x85e3, 0x8615,
	0x8647, 0x867a, 0x86ac, 0x86de, 0x8710, 0x8742, 0x8774, 0x87a7,
	0x87d9, 0x880b, 0x883d, 0x886f, 0x88a1, 0x88d4, 0x8906, 0x8938,
	0x896a, 0x899c, 0x89ce, 0x8a00, 0x8a32, 0x8a65, 0x8a97, 0x8ac9,
	0x8afb, 0x8b2d, 0x8b5f, 0x8b91, 0x8bc3, 0x8bf5, 0x8c27, 0x8c59,
	0x8c8b, 0x8cbd, 0x8cef, 0x8d21, 0x8d53, 0x8d85, 0x8db7, 0x8de9,
	0x8e1b, 0x8e4d, 0x8e7f, 0x8eb1, 0x8ee3, 0x8f15, 0x8f47, 0x8f79,
	0x8fab, 0x8fdc, 0x900e, 0x9040, 0x9072, 0x90a4, 0x90d6, 0x9107,
	0x9139, 0x916b, 0x919d, 0x91cf, 0x9200, 0x9232, 0x9264, 0x9296,
	0x92c7, 0x92f9, 0x932b, 0x935d, 0x938e, 0x93c0, 0x93f2, 0x9423,
	0x9455, 0x9486, 0x94b8, 0x94ea, 0x951b, 0x954d, 0x957e, 0x95b0,
	0x95e1, 0x9613, 0x9644, 0x9676, 0x96a7, 0x96d9, 0x970a, 0x973c,
	0x976d, 0x979f, 0x97d0, 0x9801, 0x9833, 0x9864, 0x9895, 0x98c7,
	0x98f8, 0x9929, 0x995b, 0x998c, 0x99bd, 0x99ee, 0x9a20, 0x9a51,
	0x9a82, 0x9ab3, 0x9ae4, 0x9b15, 0x9b46, 0x9b78, 0x9ba9, 0x9bda,
	0x9c0b, 0x9c3c, 0x9c6d, 0x9c9e, 0x9ccf, 0x9d00, 0x9d31, 0x9d62,
	0x9d93, 0x9dc3, 0x9df4, 0x9e25, 0x9e56, 0x9e87, 0x9eb8, 0x9ee8,
	0x9f19, 0x9f4a, 0x9f7b, 0x9fab, 0x9fdc, 0xa00d, 0xa03d, 0xa06e,
	0xa09f, 0xa0cf, 0xa100, 0xa130, 0xa161, 0xa191, 0xa1c2, 0xa1f2,
	0xa223, 0xa253, 0xa284, 0xa2b4, 0xa2e4, 0xa315, 0xa345, 0xa375,
	0xa3a6, 0xa3d6, 0xa406, 0xa436, 0xa467, 0xa497, 0xa4c7, 0xa4f7,
	0xa527, 0xa557, 0xa587, 0xa5b7, 0xa5e7, 0xa617, 0xa647, 0xa677,
	0xa6a7, 0xa6d7, 0xa707, 0xa737, 0xa767, 0xa797, 0xa7c6, 0xa7f6,
	0xa826, 0xa856, 0xa885, 0xa8b5, 0xa8e5, 0xa914, 0xa944, 0xa973,
	0xa9a3, 0xa9d2, 0xaa02, 0xaa31, 0xaa61, 0xaa90, 0xaac0, 0xaaef,
	0xab1e, 0xab4e, 0xab7d, 0xabac, 0xabdb, 0xac0b, 0xac3a, 0xac69,
	0xac98, 0xacc7, 0xacf6, 0xad25, 0xad54, 0xad83, 0xadb2, 0xade1,
	0xae10, 0xae3f, 0xae6e, 0xae9d, 0xaecc, 0xaefa, 0xaf29, 0xaf58,
	0xaf86, 0xafb5, 0xafe4, 0xb012, 0xb041, 0xb06f, 0xb09e, 0xb0cc,
	0xb0fb, 0xb129, 0xb158, 0xb186, 0xb1b4, 0xb1e3, 0xb211, 0xb23f,
	0xb26d, 0xb29c, 0xb2ca, 0xb2f8, 0xb326, 0xb354, 0xb382, 0xb3b0,
	0xb3de, 0xb40c, 0xb43a, 0xb468, 0xb496, 0xb4c3, 0xb4f1, 0xb51f,
	0xb54d, 0xb57a, 0xb5a8, 0xb5d6, 0xb603, 0xb631, 0xb65e, 0xb68c,
	0xb6b9, 0xb6e7, 0xb714, 0xb741, 0xb76f, 0xb79c, 0xb7c9, 0xb7f6,
	0xb824, 0xb851, 0xb87e, 0xb8ab, 0xb8d8, 0xb905, 0xb932, 0xb95f,
	0xb98c, 0xb9b9, 0xb9e6, 0xba12, 0xba3f, 0xba6c, 0xba99, 0xbac5,
	0xbaf2, 0xbb1f, 0xbb4b, 0xbb78, 0xbba4, 0xbbd1, 0xbbfd, 0xbc29,
	0xbc56, 0xbc82, 0xbcae, 0xbcdb, 0xbd07, 0xbd33, 0xbd5f, 0xbd8b,
	0xbdb7, 0xbde3, 0xbe0f, 0xbe3b, 0xbe67, 0xbe93, 0xbebf, 0xbeeb,
	0xbf16, 0xbf42, 0xbf6e, 0xbf99, 0xbfc5, 0xbff0, 0xc01c, 0xc047,
	0xc073, 0xc09e, 0xc0ca, 0xc0f5, 0xc120, 0xc14c, 0xc177, 0xc1a2,
	0xc1cd, 0xc1f8, 0xc223, 0xc24e, 0xc279, 0xc2a4, 0xc2cf, 0xc2fa,
	0xc325, 0xc350, 0xc37a, 0xc3a5, 0xc3d0, 0xc3fa, 0xc425, 0xc44f,
	0xc47a, 0xc4a4, 0xc4cf, 0xc4f9, 0xc523, 0xc54e, 0xc578, 0xc5a2,
	0xc5cc, 0xc5f6, 0xc620, 0xc64a, 0xc674, 0xc69e, 0xc6c8, 0xc6f2,
	0xc71c, 0xc746, 0xc76f, 0xc799, 0xc7c3, 0xc7ec, 0xc816, 0xc83f,
	0xc869, 0xc892, 0xc8bc, 0xc8e5, 0xc90e, 0xc938, 0xc961, 0xc98a,
	0xc9b3, 0xc9dc, 0xca05, 0xca2e, 0xca57, 0xca80, 0xcaa9, 0xcad2,
	0xcafa, 0xcb23, 0xcb4c, 0xcb74, 0xcb9d, 0xcbc5, 0xcbee, 0xcc16,
	0xcc3f, 0xcc67, 0xcc8f, 0xccb8, 0xcce0, 0xcd08, 0xcd30, 0xcd58,
	0xcd80, 0xcda8, 0xcdd0, 0xcdf8, 0xce20, 0xce48, 0xce6f, 0xce97,
	0xcebf, 0xcee6, 0xcf0e, 0xcf35, 0xcf5d, 0xcf84, 0xcfac, 0xcfd3,
	0xcffa, 0xd021, 0xd049, 0xd070, 0xd097, 0xd0be, 0xd0e5, 0xd10c,
	0xd133, 0xd159, 0xd180, 0xd1a7, 0xd1ce, 0xd1f4, 0xd21b, 0xd241,
	0xd268, 0xd28e, 0xd2b5, 0xd2db, 0xd301, 0xd328, 0xd34e, 0xd374,
	0xd39a, 0xd3c0, 0xd3e6, 0xd40c, 0xd432, 0xd458, 0xd47d, 0xd4a3,
	0xd4c9, 0xd4ef, 0xd514, 0xd53a, 0xd55f, 0xd585, 0xd5aa, 0xd5cf,
	0xd5f4, 0xd61a, 0xd63f, 0xd664, 0xd689, 0xd6ae, 0xd6d3, 0xd6f8,
	0xd71d, 0xd742, 0xd766, 0xd78b, 0xd7b0, 0xd7d4, 0xd7f9, 0xd81d,
	0xd842, 0xd866, 0xd88a, 0xd8af, 0xd8d3, 0xd8f7, 0xd91b, 0xd93f,
	0xd963, 0xd987, 0xd9ab, 0xd9cf, 0xd9f3, 0xda16, 0xda3a, 0xda5e,
	0xda81, 0xdaa5, 0xdac8, 0xdaec, 0xdb0f, 0xdb32, 0xdb56, 0xdb79,
	0xdb9c, 0xdbbf, 0xdbe2, 0xdc05, 0xdc28, 0xdc4b, 0xdc6d, 0xdc90,
	0xdcb3, 0xdcd6, 0xdcf8, 0xdd1b, 0xdd3d, 0xdd5f, 0xdd82, 0xdda4,
	0xddc6, 0xdde9, 0xde0b, 0xde2d, 0xde4f, 0xde71, 0xde93, 0xdeb4,
	0xded6, 0xdef8, 0xdf1a, 0xdf3b, 0xdf5d, 0xdf7e, 0xdfa0, 0xdfc1,
	0xdfe2, 0xe004, 0xe025, 0xe046, 0xe067, 0xe088, 0xe0a9, 0xe0ca,
	0xe0eb, 0xe10c, 0xe12d, 0xe14d, 0xe16e, 0xe18e, 0xe1af, 0xe1cf,
	0xe1f0, 0xe210, 0xe230, 0xe251, 0xe271, 0xe291, 0xe2b1, 0xe2d1,
	0xe2f1, 0xe311, 0xe330, 0xe350, 0xe370, 0xe38f, 0xe3af, 0xe3ce,
	0xe3ee, 0xe40d, 0xe42d, 0xe44c, 0xe46b, 0xe48a, 0xe4a9, 0xe4c8,
	0xe4e7, 0xe506, 0xe525, 0xe544, 0xe562, 0xe581, 0xe5a0, 0xe5be,
	0xe5dd, 0xe5fb, 0xe619, 0xe638, 0xe656, 0xe674, 0xe692, 0xe6b0,
	0xe6ce, 0xe6ec, 0xe70a, 0xe728, 0xe745, 0xe763, 0xe781, 0xe79e,
	0xe7bc, 0xe7d9, 0xe7f7, 0xe814, 0xe831, 0xe84e, 0xe86b, 0xe888,
	0xe8a5, 0xe8c2, 0xe8df, 0xe8fc, 0xe919, 0xe935, 0xe952, 0xe96e,
	0xe98b, 0xe9a7, 0xe9c4, 0xe9e0, 0xe9fc, 0xea18, 0xea34, 0xea50,
	0xea6c, 0xea88, 0xeaa4, 0xeac0, 0xeadb, 0xeaf7, 0xeb13, 0xeb2e,
	0xeb4a, 0xeb65, 0xeb80, 0xeb9c, 0xebb7, 0xebd2, 0xebed, 0xec08,
	0xec23, 0xec3e, 0xec58, 0xec73, 0xec8e, 0xeca8, 0xecc3, 0xecdd,
	0xecf8, 0xed12, 0xed2c, 0xed47, 0xed61, 0xed7b, 0xed95, 0xedaf,
	0xedc9, 0xede3, 0xedfc, 0xee16, 0xee30, 0xee49, 0xee63, 0xee7c,
	0xee95, 0xeeaf, 0xeec8, 0xeee1, 0xeefa, 0xef13, 0xef2c, 0xef45,
	0xef5e, 0xef76, 0xef8f, 0xefa8, 0xefc0, 0xefd9, 0xeff1, 0xf009,
	0xf022, 0xf03a, 0xf052, 0xf06a, 0xf082, 0xf09a, 0xf0b2, 0xf0ca,
	0xf0e1, 0xf0f9, 0xf111, 0xf128, 0xf140, 0xf157, 0xf16e, 0xf186,
	0xf19d, 0xf1b4, 0xf1cb, 0xf1e2, 0xf1f9, 0xf210, 0xf226, 0xf23d,
	0xf254, 0xf26a, 0xf281, 0xf297, 0xf2ae, 0xf2c4, 0xf2da, 0xf2f0,
	0xf306, 0xf31c, 0xf332, 0xf348, 0xf35e, 0xf374, 0xf389, 0xf39f,
	0xf3b5, 0xf3ca, 0xf3df, 0xf3f5, 0xf40a, 0xf41f, 0xf434, 0xf449,
	0xf45e, 0xf473, 0xf488, 0xf49d, 0xf4b1, 0xf4c6, 0xf4db, 0xf4ef,
	0xf503, 0xf518, 0xf52c, 0xf540, 0xf554, 0xf568, 0xf57c, 0xf590,
	0xf5a4, 0xf5b8, 0xf5cc, 0xf5df, 0xf5f3, 0xf606, 0xf61a, 0xf62d,
	0xf640, 0xf653, 0xf667, 0xf67a, 0xf68d, 0xf6a0, 0xf6b2, 0xf6c5,
	0xf6d8, 0xf6ea, 0xf6fd, 0xf710, 0xf722, 0xf734, 0xf747, 0xf759,
	0xf76b, 0xf77d, 0xf78f, 0xf7a1, 0xf7b3, 0xf7c4, 0xf7d6, 0xf7e8,
	0xf7f9, 0xf80b, 0xf81c, 0xf82e, 0xf83f, 0xf850, 0xf861, 0xf872,
	0xf883, 0xf894, 0xf8a5, 0xf8b6, 0xf8c6, 0xf8d7, 0xf8e7, 0xf8f8,
	0xf908, 0xf919, 0xf929, 0xf939, 0xf949, 0xf959, 0xf969, 0xf979,
	0xf989, 0xf998, 0xf9a8, 0xf9b8, 0xf9c7, 0xf9d7, 0xf9e6, 0xf9f5,
	0xfa04, 0xfa14, 0xfa23, 0xfa32, 0xfa41, 0xfa4f, 0xfa5e, 0xfa6d,
	0xfa7c, 0xfa8a, 0xfa99, 0xfaa7, 0xfab5, 0xfac4, 0xfad2, 0xfae0,
	0xfaee, 0xfafc, 0xfb0a, 0xfb18, 0xfb25, 0xfb33, 0xfb41, 0xfb4e,
	0xfb5c, 0xfb69, 0xfb76, 0xfb83, 0xfb91, 0xfb9e, 0xfbab, 0xfbb8,
	0xfbc4, 0xfbd1, 0xfbde, 0xfbeb, 0xfbf7, 0xfc04, 0xfc10, 0xfc1c,
	0xfc29, 0xfc35, 0xfc41, 0xfc4d, 0xfc59, 0xfc65, 0xfc70, 0xfc7c,
	0xfc88, 0xfc93, 0xfc9f, 0xfcaa, 0xfcb6, 0xfcc1, 0xfccc, 0xfcd7,
	0xfce2, 0xfced, 0xfcf8, 0xfd03, 0xfd0e, 0xfd18, 0xfd23, 0xfd2e,
	0xfd38, 0xfd42, 0xfd4d, 0xfd57, 0xfd61, 0xfd6b, 0xfd75, 0xfd7f,
	0xfd89, 0xfd93, 0xfd9c, 0xfda6, 0xfdb0, 0xfdb9, 0xfdc2, 0xfdcc,
	0xfdd5, 0xfdde, 0xfde7, 0xfdf0, 0xfdf9, 0xfe02, 0xfe0b, 0xfe13,
	0xfe1c, 0xfe25, 0xfe2d, 0xfe36, 0xfe3e, 0xfe46, 0xfe4e, 0xfe56,
	0xfe5e, 0xfe66, 0xfe6e, 0xfe76, 0xfe7e, 0xfe85, 0xfe8d, 0xfe94,
	0xfe9c, 0xfea3, 0xfeaa, 0xfeb2, 0xfeb9, 0xfec0, 0xfec7, 0xfece,
	0xfed4, 0xfedb, 0xfee2, 0xfee8, 0xfeef, 0xfef5, 0xfefc, 0xff02,
	0xff08, 0xff0e, 0xff14, 0xff1a, 0xff20, 0xff26, 0xff2c, 0xff31,
	0xff37, 0xff3c, 0xff42, 0xff47, 0xff4c, 0xff52, 0xff57, 0xff5c,
	0xff61, 0xff66, 0xff6a, 0xff6f, 0xff74, 0xff78, 0xff7d, 0xff81,
	0xff86, 0xff8a, 0xff8e, 0xff92, 0xff96, 0xff9a, 0xff9e, 0xffa2,
	0xffa6, 0xffa9, 0xffad, 0xffb0, 0xffb4, 0xffb7, 0xffbb, 0xffbe,
	0xffc1, 0xffc4, 0xffc7, 0xffca, 0xffcd, 0xffcf, 0xffd2, 0xffd5,
	0xffd7, 0xffd9, 0xffdc, 0xffde, 0xffe0, 0xffe2, 0xffe4, 0xffe6,
	0xffe8, 0xffea, 0xffec, 0xffee, 0xffef, 0xfff1, 0xfff2, 0xfff3,
	0xfff5, 0xfff6, 0xfff7, 0xfff8, 0xfff9, 0xfffa, 0xfffb, 0xfffb,
	0xfffc, 0xfffd, 0xfffd, 0xfffe, 0xfffe, 0xfffe, 0xfffe, 0xfffe,
	0xffff, 0xfffe, 0xfffe, 0xfffe, 0xfffe, 0xfffe, 0xfffd, 0xfffd,
	0xfffc, 0xfffb, 0xfffb, 0xfffa, 0xfff9, 0xfff8, 0xfff7, 0xfff6,
	0xfff5, 0xfff3, 0xfff2, 0xfff1, 0xffef, 0xffee, 0xffec, 0xffea,
	0xffe8, 0xffe6, 0xffe4, 0xffe2, 0xffe0, 0xffde, 0xffdc, 0xffd9,
	0xffd7, 0xffd5, 0xffd2, 0xffcf, 0xffcd, 0xffca, 0xffc7, 0xffc4,
	0xffc1, 0xffbe, 0xffbb, 0xffb7, 0xffb4, 0xffb0, 0xffad, 0xffa9,
	0xffa6, 0xffa2, 0xff9e, 0xff9a, 0xff96, 0xff92, 0xff8e, 0xff8a,
	0xff86, 0xff81, 0xff7d, 0xff78, 0xff74, 0xff6f, 0xff6a, 0xff66,
	0xff61, 0xff5c, 0xff57, 0xff52, 0xff4c, 0xff47, 0xff42, 0xff3c,
	0xff37, 0xff31, 0xff2c, 0xff26, 0xff20, 0xff1a, 0xff14, 0xff0e,
	0xff08, 0xff02, 0xfefc, 0xfef5, 0xfeef, 0xfee8, 0xfee2, 0xfedb,
	0xfed4, 0xfece, 0xfec7, 0xfec0, 0xfeb9, 0xfeb2, 0xfeaa, 0xfea3,
	0xfe9c, 0xfe94, 0xfe8d, 0xfe85, 0xfe7e, 0xfe76, 0xfe6e, 0xfe66,
	0xfe5e, 0xfe56, 0xfe4e, 0xfe46, 0xfe3e, 0xfe36, 0xfe2d, 0xfe25,
	0xfe1c, 0xfe13, 0xfe0b, 0xfe02, 0xfdf9, 0xfdf0, 0xfde7, 0xfdde,
	0xfdd5, 0xfdcc, 0xfdc2, 0xfdb9, 0xfdb0, 0xfda6, 0xfd9c, 0xfd93,
	0xfd89, 0xfd7f, 0xfd75, 0xfd6b, 0xfd61, 0xfd57, 0xfd4d, 0xfd42,
	0xfd38, 0xfd2e, 0xfd23, 0xfd18, 0xfd0e, 0xfd03, 0xfcf8, 0xfced,
	0xfce2, 0xfcd7, 0xfccc, 0xfcc1, 0xfcb6, 0xfcaa, 0xfc9f, 0xfc93,
	0xfc88, 0xfc7c, 0xfc70, 0xfc65, 0xfc59, 0xfc4d, 0xfc41, 0xfc35,
	0xfc29, 0xfc1c, 0xfc10, 0xfc04, 0xfbf7, 0xfbeb, 0xfbde, 0xfbd1,
	0xfbc4, 0xfbb8, 0xfbab, 0xfb9e, 0xfb91, 0xfb83, 0xfb76, 0xfb69,
	0xfb5c, 0xfb4e, 0xfb41, 0xfb33, 0xfb25, 0xfb18, 0xfb0a, 0xfafc,
	0xfaee, 0xfae0, 0xfad2, 0xfac4, 0xfab5, 0xfaa7, 0xfa99, 0xfa8a,
	0xfa7c, 0xfa6d, 0xfa5e, 0xfa4f, 0xfa41, 0xfa32, 0xfa23, 0xfa14,
	0xfa04, 0xf9f5, 0xf9e6, 0xf9d7, 0xf9c7, 0xf9b8, 0xf9a8, 0xf998,
	0xf989, 0xf979, 0xf969, 0xf959, 0xf949, 0xf939, 0xf929, 0xf919,
	0xf908, 0xf8f8, 0xf8e7, 0xf8d7, 0xf8c6, 0xf8b6, 0xf8a5, 0xf894,
	0xf883, 0xf872, 0xf861, 0xf850, 0xf83f, 0xf82e, 0xf81c, 0xf80b,
	0xf7f9, 0xf7e8, 0xf7d6, 0xf7c4, 0xf7b3, 0xf7a1, 0xf78f, 0xf77d,
	0xf76b, 0xf759, 0xf747, 0xf734, 0xf722, 0xf710, 0xf6fd, 0xf6ea,
	0xf6d8, 0xf6c5, 0xf6b2, 0xf6a0, 0xf68d, 0xf67a, 0xf667, 0xf653,
	0xf640, 0xf62d, 0xf61a, 0xf606, 0xf5f3, 0xf5df, 0xf5cc, 0xf5b8,
	0xf5a4, 0xf590, 0xf57c, 0xf568, 0xf554, 0xf540, 0xf52c, 0xf518,
	0xf503, 0xf4ef, 0xf4db, 0xf4c6, 0xf4b1, 0xf49d, 0xf488, 0xf473,
	0xf45e, 0xf449, 0xf434, 0xf41f, 0xf40a, 0xf3f5, 0xf3df, 0xf3ca,
	0xf3b5, 0xf39f, 0xf389, 0xf374, 0xf35e, 0xf348, 0xf332, 0xf31c,
	0xf306, 0xf2f0, 0xf2da, 0xf2c4, 0xf2ae, 0xf297, 0xf281, 0xf26a,
	0xf254, 0xf23d, 0xf226, 0xf210, 0xf1f9, 0xf1e2, 0xf1cb, 0xf1b4,
	0xf19d, 0xf186, 0xf16e, 0xf157, 0xf140, 0xf128, 0xf111, 0xf0f9,
	0xf0e1, 0xf0ca, 0xf0b2, 0xf09a, 0xf082, 0xf06a, 0xf052, 0xf03a,
	0xf022, 0xf009, 0xeff1, 0xefd9, 0xefc0, 0xefa8, 0xef8f, 0xef76,
	0xef5e, 0xef45, 0xef2c, 0xef13, 0xeefa, 0xeee1, 0xeec8, 0xeeaf,
	0xee95, 0xee7c, 0xee63, 0xee49, 0xee30, 0xee16, 0xedfc, 0xede3,
	0xedc9, 0xedaf, 0xed95, 0xed7b, 0xed61, 0xed47, 0xed2c, 0xed12,
	0xecf8, 0xecdd, 0xecc3, 0xeca8, 0xec8e, 0xec73, 0xec58, 0xec3e,
	0xec23, 0xec08, 0xebed, 0xebd2, 0xebb7, 0xeb9c, 0xeb80, 0xeb65,
	0xeb4a, 0xeb2e, 0xeb13, 0xeaf7, 0xeadb, 0xeac0, 0xeaa4, 0xea88,
	0xea6c, 0xea50, 0xea34, 0xea18, 0xe9fc, 0xe9e0, 0xe9c4, 0xe9a7,
	0xe98b, 0xe96e, 0xe952, 0xe935, 0xe919, 0xe8fc, 0xe8df, 0xe8c2,
	0xe8a5, 0xe888, 0xe86b, 0xe84e, 0xe831, 0xe814, 0xe7f7, 0xe7d9,
	0xe7bc, 0xe79e, 0xe781, 0xe763, 0xe745, 0xe728, 0xe70a, 0xe6ec,
	0xe6ce, 0xe6b0, 0xe692, 0xe674, 0xe656, 0xe638, 0xe619, 0xe5fb,
	0xe5dd, 0xe5be, 0xe5a0, 0xe581, 0xe562, 0xe544, 0xe525, 0xe506,
	0xe4e7, 0xe4c8, 0xe4a9, 0xe48a, 0xe46b, 0xe44c, 0xe42d, 0xe40d,
	0xe3ee, 0xe3ce, 0xe3af, 0xe38f, 0xe370, 0xe350, 0xe330, 0xe311,
	0xe2f1, 0xe2d1, 0xe2b1, 0xe291, 0xe271, 0xe251, 0xe230, 0xe210,
	0xe1f0, 0xe1cf, 0xe1af, 0xe18e, 0xe16e, 0xe14d, 0xe12d, 0xe10c,
	0xe0eb, 0xe0ca, 0xe0a9, 0xe088, 0xe067, 0xe046, 0xe025, 0xe004,
	0xdfe2, 0xdfc1, 0xdfa0, 0xdf7e, 0xdf5d, 0xdf3b, 0xdf1a, 0xdef8,
	0xded6, 0xdeb4, 0xde93, 0xde71, 0xde4f, 0xde2d, 0xde0b, 0xdde9,
	0xddc6, 0xdda4, 0xdd82, 0xdd5f, 0xdd3d, 0xdd1b, 0xdcf8, 0xdcd6,
	0xdcb3, 0xdc90, 0xdc6d, 0xdc4b, 0xdc28, 0xdc05, 0xdbe2, 0xdbbf,
	0xdb9c, 0xdb79, 0xdb56, 0xdb32, 0xdb0f, 0xdaec, 0xdac8, 0xdaa5,
	0xda81, 0xda5e, 0xda3a, 0xda16, 0xd9f3, 0xd9cf, 0xd9ab, 0xd987,
	0xd963, 0xd93f, 0xd91b, 0xd8f7, 0xd8d3, 0xd8af, 0xd88a, 0xd866,
	0xd842, 0xd81d, 0xd7f9, 0xd7d4, 0xd7b0, 0xd78b, 0xd766, 0xd742,
	0xd71d, 0xd6f8, 0xd6d3, 0xd6ae, 0xd689, 0xd664, 0xd63f, 0xd61a,
	0xd5f4, 0xd5cf, 0xd5aa, 0xd585, 0xd55f, 0xd53a, 0xd514, 0xd4ef,
	0xd4c9, 0xd4a3, 0xd47d, 0xd458, 0xd432, 0xd40c, 0xd3e6, 0xd3c0,
	0xd39a, 0xd374, 0xd34e, 0xd328, 0xd301, 0xd2db, 0xd2b5, 0xd28e,
	0xd268, 0xd241, 0xd21b, 0xd1f4, 0xd1ce, 0xd1a7, 0xd180, 0xd159,
	0xd133, 0xd10c, 0xd0e5, 0xd0be, 0xd097, 0xd070, 0xd049, 0xd021,
	0xcffa, 0xcfd3, 0xcfac, 0xcf84, 0xcf5d, 0xcf35, 0xcf0e, 0xcee6,
	0xcebf, 0xce97, 0xce6f, 0xce48, 0xce20, 0xcdf8, 0xcdd0, 0xcda8,
	0xcd80, 0xcd58, 0xcd30, 0xcd08, 0xcce0, 0xccb8, 0xcc8f, 0xcc67,
	0xcc3f, 0xcc16, 0xcbee, 0xcbc5, 0xcb9d, 0xcb74, 0xcb4c, 0xcb23,
	0xcafa, 0xcad2, 0xcaa9, 0xca80, 0xca57, 0xca2e, 0xca05, 0xc9dc,
	0xc9b3, 0xc98a, 0xc961, 0xc938, 0xc90e, 0xc8e5, 0xc8bc, 0xc892,
	0xc869, 0xc83f, 0xc816, 0xc7ec, 0xc7c3, 0xc799, 0xc76f, 0xc746,
	0xc71c, 0xc6f2, 0xc6c8, 0xc69e, 0xc674, 0xc64a, 0xc620, 0xc5f6,
	0xc5cc, 0xc5a2, 0xc578, 0xc54e, 0xc523, 0xc4f9, 0xc4cf, 0xc4a4,
	0xc47a, 0xc44f, 0xc425, 0xc3fa, 0xc3d0, 0xc3a5, 0xc37a, 0xc350,
	0xc325, 0xc2fa, 0xc2cf, 0xc2a4, 0xc279, 0xc24e, 0xc223, 0xc1f8,
	0xc1cd, 0xc1a2, 0xc177, 0xc14c, 0xc120, 0xc0f5, 0xc0ca, 0xc09e,
	0xc073, 0xc047, 0xc01c, 0xbff0, 0xbfc5, 0xbf99, 0xbf6e, 0xbf42,
	0xbf16, 0xbeeb, 0xbebf, 0xbe93, 0xbe67, 0xbe3b, 0xbe0f, 0xbde3,
	0xbdb7, 0xbd8b, 0xbd5f, 0xbd33, 0xbd07, 0xbcdb, 0xbcae, 0xbc82,
	0xbc56, 0xbc29, 0xbbfd, 0xbbd1, 0xbba4, 0xbb78, 0xbb4b, 0xbb1f,
	0xbaf2, 0xbac5, 0xba99, 0xba6c, 0xba3f, 0xba12, 0xb9e6, 0xb9b9,
	0xb98c, 0xb95f, 0xb932, 0xb905, 0xb8d8, 0xb8ab, 0xb87e, 0xb851,
	0xb824, 0xb7f6, 0xb7c9, 0xb79c, 0xb76f, 0xb741, 0xb714, 0xb6e7,
	0xb6b9, 0xb68c, 0xb65e, 0xb631, 0xb603, 0xb5d6, 0xb5a8, 0xb57a,
	0xb54d, 0xb51f, 0xb4f1, 0xb4c3, 0xb496, 0xb468, 0xb43a, 0xb40c,
	0xb3de, 0xb3b0, 0xb382, 0xb354, 0xb326, 0xb2f8, 0xb2ca, 0xb29c,
	0xb26d, 0xb23f, 0xb211, 0xb1e3, 0xb1b4, 0xb186, 0xb158, 0xb129,
	0xb0fb, 0xb0cc, 0xb09e, 0xb06f, 0xb041, 0xb012, 0xafe4, 0xafb5,
	0xaf86, 0xaf58, 0xaf29, 0xaefa, 0xaecc, 0xae9d, 0xae6e, 0xae3f,
	0xae10, 0xade1, 0xadb2, 0xad83, 0xad54, 0xad25, 0xacf6, 0xacc7,
	0xac98, 0xac69, 0xac3a, 0xac0b, 0xabdb, 0xabac, 0xab7d, 0xab4e,
	0xab1e, 0xaaef, 0xaac0, 0xaa90, 0xaa61, 0xaa31, 0xaa02, 0xa9d2,
	0xa9a3, 0xa973, 0xa944, 0xa914, 0xa8e5, 0xa8b5, 0xa885, 0xa856,
	0xa826, 0xa7f6, 0xa7c6, 0xa797, 0xa767, 0xa737, 0xa707, 0xa6d7,
	0xa6a7, 0xa677, 0xa647, 0xa617, 0xa5e7, 0xa5b7, 0xa587, 0xa557,
	0xa527, 0xa4f7, 0xa4c7, 0xa497, 0xa467, 0xa436, 0xa406, 0xa3d6,
	0xa3a6, 0xa375, 0xa345, 0xa315, 0xa2e4, 0xa2b4, 0xa284, 0xa253,
	0xa223, 0xa1f2, 0xa1c2, 0xa191, 0xa161, 0xa130, 0xa100, 0xa0cf,
	0xa09f, 0xa06e, 0xa03d, 0xa00d, 0x9fdc, 0x9fab, 0x9f7b, 0x9f4a,
	0x9f19, 0x9ee8, 0x9eb8, 0x9e87, 0x9e56, 0x9e25, 0x9df4, 0x9dc3,
	0x9d93, 0x9d62, 0x9d31, 0x9d00, 0x9ccf, 0x9c9e, 0x9c6d, 0x9c3c,
	0x9c0b, 0x9bda, 0x9ba9, 0x9b78, 0x9b46, 0x9b15, 0x9ae4, 0x9ab3,
	0x9a82, 0x9a51, 0x9a20, 0x99ee, 0x99bd, 0x998c, 0x995b, 0x9929,
	0x98f8, 0x98c7, 0x9895, 0x9864, 0x9833, 0x9801, 0x97d0, 0x979f,
	0x976d, 0x973c, 0x970a, 0x96d9, 0x96a7, 0x9676, 0x9644, 0x9613,
	0x95e1, 0x95b0, 0x957e, 0x954d, 0x951b, 0x94ea, 0x94b8, 0x9486,
	0x9455, 0x9423, 0x93f2, 0x93c0, 0x938e, 0x935d, 0x932b, 0x92f9,
	0x92c7, 0x9296, 0x9264, 0x9232, 0x9200, 0x91cf, 0x919d, 0x916b,
	0x9139, 0x9107, 0x90d6, 0x90a4, 0x9072, 0x9040, 0x900e, 0x8fdc,
	0x8fab, 0x8f79, 0x8f47, 0x8f15, 0x8ee3, 0x8eb1, 0x8e7f, 0x8e4d,
	0x8e1b, 0x8de9, 0x8db7, 0x8d85, 0x8d53, 0x8d21, 0x8cef, 0x8cbd,
	0x8c8b, 0x8c59, 0x8c27, 0x8bf5, 0x8bc3, 0x8b91, 0x8b5f, 0x8b2d,
	0x8afb, 0x8ac9, 0x8a97, 0x8a65, 0x8a32, 0x8a00, 0x89ce, 0x899c,
	0x896a, 0x8938, 0x8906, 0x88d4, 0x88a1, 0x886f, 0x883d, 0x880b,
	0x87d9, 0x87a7, 0x8774, 0x8742, 0x8710, 0x86de, 0x86ac, 0x867a,
	0x8647, 0x8615, 0x85e3, 0x85b1, 0x857e, 0x854c, 0x851a, 0x84e8,
	0x84b6, 0x8483, 0x8451, 0x841f, 0x83ed, 0x83ba, 0x8388, 0x8356,
	0x8324, 0x82f1, 0x82bf, 0x828d, 0x825b, 0x8228, 0x81f6, 0x81c4,
	0x8192, 0x815f, 0x812d, 0x80fb, 0x80c9, 0x8096, 0x8064, 0x8032,
	0x8000, 0x7fcd, 0x7f9b, 0x7f69, 0x7f36, 0x7f04, 0x7ed2, 0x7ea0,
	0x7e6d, 0x7e3b, 0x7e09, 0x7dd7, 0x7da4, 0x7d72, 0x7d40, 0x7d0e,
	0x7cdb, 0x7ca9, 0x7c77, 0x7c45, 0x7c12, 0x7be0, 0x7bae, 0x7b7c,
	0x7b49, 0x7b17, 0x7ae5, 0x7ab3, 0x7a81, 0x7a4e, 0x7a1c, 0x79ea,
	0x79b8, 0x7985, 0x7953, 0x7921, 0x78ef, 0x78bd, 0x788b, 0x7858,
	0x7826, 0x77f4, 0x77c2, 0x7790, 0x775e, 0x772b, 0x76f9, 0x76c7,
	0x7695, 0x7663, 0x7631, 0x75ff, 0x75cd, 0x759a, 0x7568, 0x7536,
	0x7504, 0x74d2, 0x74a0, 0x746e, 0x743c, 0x740a, 0x73d8, 0x73a6,
	0x7374, 0x7342, 0x7310, 0x72de, 0x72ac, 0x727a, 0x7248, 0x7216,
	0x71e4, 0x71b2, 0x7180, 0x714e, 0x711c, 0x70ea, 0x70b8, 0x7086,
	0x7054, 0x7023, 0x6ff1, 0x6fbf, 0x6f8d, 0x6f5b, 0x6f29, 0x6ef8,
	0x6ec6, 0x6e94, 0x6e62, 0x6e30, 0x6dff, 0x6dcd, 0x6d9b, 0x6d69,
	0x6d38, 0x6d06, 0x6cd4, 0x6ca2, 0x6c71, 0x6c3f, 0x6c0d, 0x6bdc,
	0x6baa, 0x6b79, 0x6b47, 0x6b15, 0x6ae4, 0x6ab2, 0x6a81, 0x6a4f,
	0x6a1e, 0x69ec, 0x69bb, 0x6989, 0x6958, 0x6926, 0x68f5, 0x68c3,
	0x6892, 0x6860, 0x682f, 0x67fe, 0x67cc, 0x679b, 0x676a, 0x6738,
	0x6707, 0x66d6, 0x66a4, 0x6673, 0x6642, 0x6611, 0x65df, 0x65ae,
	0x657d, 0x654c, 0x651b, 0x64ea, 0x64b9, 0x6487, 0x6456, 0x6425,
	0x63f4, 0x63c3, 0x6392, 0x6361, 0x6330, 0x62ff, 0x62ce, 0x629d,
	0x626c, 0x623c, 0x620b, 0x61da, 0x61a9, 0x6178, 0x6147, 0x6117,
	0x60e6, 0x60b5, 0x6084, 0x6054, 0x6023, 0x5ff2, 0x5fc2, 0x5f91,
	0x5f60, 0x5f30, 0x5eff, 0x5ecf, 0x5e9e, 0x5e6e, 0x5e3d, 0x5e0d,
	0x5ddc, 0x5dac, 0x5d7b, 0x5d4b, 0x5d1b, 0x5cea, 0x5cba, 0x5c8a,
	0x5c59, 0x5c29, 0x5bf9, 0x5bc9, 0x5b98, 0x5b68, 0x5b38, 0x5b08,
	0x5ad8, 0x5aa8, 0x5a78, 0x5a48, 0x5a18, 0x59e8, 0x59b8, 0x5988,
	0x5958, 0x5928, 0x58f8, 0x58c8, 0x5898, 0x5868, 0x5839, 0x5809,
	0x57d9, 0x57a9, 0x577a, 0x574a, 0x571a, 0x56eb, 0x56bb, 0x568c,
	0x565c, 0x562d, 0x55fd, 0x55ce, 0x559e, 0x556f, 0x553f, 0x5510,
	0x54e1, 0x54b1, 0x5482, 0x5453, 0x5424, 0x53f4, 0x53c5, 0x5396,
	0x5367, 0x5338, 0x5309, 0x52da, 0x52ab, 0x527c, 0x524d, 0x521e,
	0x51ef, 0x51c0, 0x5191, 0x5162, 0x5133, 0x5105, 0x50d6, 0x50a7,
	0x5079, 0x504a, 0x501b, 0x4fed, 0x4fbe, 0x4f90, 0x4f61, 0x4f33,
	0x4f04, 0x4ed6, 0x4ea7, 0x4e79, 0x4e4b, 0x4e1c, 0x4dee, 0x4dc0,
	0x4d92, 0x4d63, 0x4d35, 0x4d07, 0x4cd9, 0x4cab, 0x4c7d, 0x4c4f,
	0x4c21, 0x4bf3, 0x4bc5, 0x4b97, 0x4b69, 0x4b3c, 0x4b0e, 0x4ae0,
	0x4ab2, 0x4a85, 0x4a57, 0x4a29, 0x49fc, 0x49ce, 0x49a1, 0x4973,
	0x4946, 0x4918, 0x48eb, 0x48be, 0x4890, 0x4863, 0x4836, 0x4809,
	0x47db, 0x47ae, 0x4781, 0x4754, 0x4727, 0x46fa, 0x46cd, 0x46a0,
	0x4673, 0x4646, 0x4619, 0x45ed, 0x45c0, 0x4593, 0x4566, 0x453a,
	0x450d, 0x44e0, 0x44b4, 0x4487, 0x445b, 0x442e, 0x4402, 0x43d6,
	0x43a9, 0x437d, 0x4351, 0x4324, 0x42f8, 0x42cc, 0x42a0, 0x4274,
	0x4248, 0x421c, 0x41f0, 0x41c4, 0x4198, 0x416c, 0x4140, 0x4114,
	0x40e9, 0x40bd, 0x4091, 0x4066, 0x403a, 0x400f, 0x3fe3, 0x3fb8,
	0x3f8c, 0x3f61, 0x3f35, 0x3f0a, 0x3edf, 0x3eb3, 0x3e88, 0x3e5d,
	0x3e32, 0x3e07, 0x3ddc, 0x3db1, 0x3d86, 0x3d5b, 0x3d30, 0x3d05,
	0x3cda, 0x3caf, 0x3c85, 0x3c5a, 0x3c2f, 0x3c05, 0x3bda, 0x3bb0,
	0x3b85, 0x3b5b, 0x3b30, 0x3b06, 0x3adc, 0x3ab1, 0x3a87, 0x3a5d,
	0x3a33, 0x3a09, 0x39df, 0x39b5, 0x398b, 0x3961, 0x3937, 0x390d,
	0x38e3, 0x38b9, 0x3890, 0x3866, 0x383c, 0x3813, 0x37e9, 0x37c0,
	0x3796, 0x376d, 0x3743, 0x371a, 0x36f1, 0x36c7, 0x369e, 0x3675,
	0x364c, 0x3623, 0x35fa, 0x35d1, 0x35a8, 0x357f, 0x3556, 0x352d,
	0x3505, 0x34dc, 0x34b3, 0x348b, 0x3462, 0x343a, 0x3411, 0x33e9,
	0x33c0, 0x3398, 0x3370, 0x3347, 0x331f, 0x32f7, 0x32cf, 0x32a7,
	0x327f, 0x3257, 0x322f, 0x3207, 0x31df, 0x31b7, 0x3190, 0x3168,
	0x3140, 0x3119, 0x30f1, 0x30ca, 0x30a2, 0x307b, 0x3053, 0x302c,
	0x3005, 0x2fde, 0x2fb6, 0x2f8f, 0x2f68, 0x2f41, 0x2f1a, 0x2ef3,
	0x2ecc, 0x2ea6, 0x2e7f, 0x2e58, 0x2e31, 0x2e0b, 0x2de4, 0x2dbe,
	0x2d97, 0x2d71, 0x2d4a, 0x2d24, 0x2cfe, 0x2cd7, 0x2cb1, 0x2c8b,
	0x2c65, 0x2c3f, 0x2c19, 0x2bf3, 0x2bcd, 0x2ba7, 0x2b82, 0x2b5c,
	0x2b36, 0x2b10, 0x2aeb, 0x2ac5, 0x2aa0, 0x2a7a, 0x2a55, 0x2a30,
	0x2a0b, 0x29e5, 0x29c0, 0x299b, 0x2976, 0x2951, 0x292c, 0x2907,
	0x28e2, 0x28bd, 0x2899, 0x2874, 0x284f, 0x282b, 0x2806, 0x27e2,
	0x27bd, 0x2799, 0x2775, 0x2750, 0x272c, 0x2708, 0x26e4, 0x26c0,
	0x269c, 0x2678, 0x2654, 0x2630, 0x260c, 0x25e9, 0x25c5, 0x25a1,
	0x257e, 0x255a, 0x2537, 0x2513, 0x24f0, 0x24cd, 0x24a9, 0x2486,
	0x2463, 0x2440, 0x241d, 0x23fa, 0x23d7, 0x23b4, 0x2392, 0x236f,
	0x234c, 0x2329, 0x2307, 0x22e4, 0x22c2, 0x22a0, 0x227d, 0x225b,
	0x2239, 0x2216, 0x21f4, 0x21d2, 0x21b0, 0x218e, 0x216c, 0x214b,
	0x2129, 0x2107, 0x20e5, 0x20c4, 0x20a2, 0x2081, 0x205f, 0x203e,
	0x201d, 0x1ffb, 0x1fda, 0x1fb9, 0x1f98, 0x1f77, 0x1f56, 0x1f35,
	0x1f14, 0x1ef3, 0x1ed2, 0x1eb2, 0x1e91, 0x1e71, 0x1e50, 0x1e30,
	0x1e0f, 0x1def, 0x1dcf, 0x1dae, 0x1d8e, 0x1d6e, 0x1d4e, 0x1d2e,
	0x1d0e, 0x1cee, 0x1ccf, 0x1caf, 0x1c8f, 0x1c70, 0x1c50, 0x1c31,
	0x1c11, 0x1bf2, 0x1bd2, 0x1bb3, 0x1b94, 0x1b75, 0x1b56, 0x1b37,
	0x1b18, 0x1af9, 0x1ada, 0x1abb, 0x1a9d, 0x1a7e, 0x1a5f, 0x1a41,
	0x1a22, 0x1a04, 0x19e6, 0x19c7, 0x19a9, 0x198b, 0x196d, 0x194f,
	0x1931, 0x1913, 0x18f5, 0x18d7, 0x18ba, 0x189c, 0x187e, 0x1861,
	0x1843, 0x1826, 0x1808, 0x17eb, 0x17ce, 0x17b1, 0x1794, 0x1777,
	0x175a, 0x173d, 0x1720, 0x1703, 0x16e6, 0x16ca, 0x16ad, 0x1691,
	0x1674, 0x1658, 0x163b, 0x161f, 0x1603, 0x15e7, 0x15cb, 0x15af,
	0x1593, 0x1577, 0x155b, 0x153f, 0x1524, 0x1508, 0x14ec, 0x14d1,
	0x14b5, 0x149a, 0x147f, 0x1463, 0x1448, 0x142d, 0x1412, 0x13f7,
	0x13dc, 0x13c1, 0x13a7, 0x138c, 0x1371, 0x1357, 0x133c, 0x1322,
	0x1307, 0x12ed, 0x12d3, 0x12b8, 0x129e, 0x1284, 0x126a, 0x1250,
	0x1236, 0x121c, 0x1203, 0x11e9, 0x11cf, 0x11b6, 0x119c, 0x1183,
	0x116a, 0x1150, 0x1137, 0x111e, 0x1105, 0x10ec, 0x10d3, 0x10ba,
	0x10a1, 0x1089, 0x1070, 0x1057, 0x103f, 0x1026, 0x100e, 0x0ff6,
	0x0fdd, 0x0fc5, 0x0fad, 0x0f95, 0x0f7d, 0x0f65, 0x0f4d, 0x0f35,
	0x0f1e, 0x0f06, 0x0eee, 0x0ed7, 0x0ebf, 0x0ea8, 0x0e91, 0x0e79,
	0x0e62, 0x0e4b, 0x0e34, 0x0e1d, 0x0e06, 0x0def, 0x0dd9, 0x0dc2,
	0x0dab, 0x0d95, 0x0d7e, 0x0d68, 0x0d51, 0x0d3b, 0x0d25, 0x0d0f,
	0x0cf9, 0x0ce3, 0x0ccd, 0x0cb7, 0x0ca1, 0x0c8b, 0x0c76, 0x0c60,
	0x0c4a, 0x0c35, 0x0c20, 0x0c0a, 0x0bf5, 0x0be0, 0x0bcb, 0x0bb6,
	0x0ba1, 0x0b8c, 0x0b77, 0x0b62, 0x0b4e, 0x0b39, 0x0b24, 0x0b10,
	0x0afc, 0x0ae7, 0x0ad3, 0x0abf, 0x0aab, 0x0a97, 0x0a83, 0x0a6f,
	0x0a5b, 0x0a47, 0x0a33, 0x0a20, 0x0a0c, 0x09f9, 0x09e5, 0x09d2,
	0x09bf, 0x09ac, 0x0998, 0x0985, 0x0972, 0x095f, 0x094d, 0x093a,
	0x0927, 0x0915, 0x0902, 0x08ef, 0x08dd, 0x08cb, 0x08b8, 0x08a6,
	0x0894, 0x0882, 0x0870, 0x085e, 0x084c, 0x083b, 0x0829, 0x0817,
	0x0806, 0x07f4, 0x07e3, 0x07d1, 0x07c0, 0x07af, 0x079e, 0x078d,
	0x077c, 0x076b, 0x075a, 0x0749, 0x0739, 0x0728, 0x0718, 0x0707,
	0x06f7, 0x06e6, 0x06d6, 0x06c6, 0x06b6, 0x06a6, 0x0696, 0x0686,
	0x0676, 0x0667, 0x0657, 0x0647, 0x0638, 0x0628, 0x0619, 0x060a,
	0x05fb, 0x05eb, 0x05dc, 0x05cd, 0x05be, 0x05b0, 0x05a1, 0x0592,
	0x0583, 0x0575, 0x0566, 0x0558, 0x054a, 0x053b, 0x052d, 0x051f,
	0x0511, 0x0503, 0x04f5, 0x04e7, 0x04da, 0x04cc, 0x04be, 0x04b1,
	0x04a3, 0x0496, 0x0489, 0x047c, 0x046e, 0x0461, 0x0454, 0x0447,
	0x043b, 0x042e, 0x0421, 0x0414, 0x0408, 0x03fb, 0x03ef, 0x03e3,
	0x03d6, 0x03ca, 0x03be, 0x03b2, 0x03a6, 0x039a, 0x038f, 0x0383,
	0x0377, 0x036c, 0x0360, 0x0355, 0x0349, 0x033e, 0x0333, 0x0328,
	0x031d, 0x0312, 0x0307, 0x02fc, 0x02f1, 0x02e7, 0x02dc, 0x02d1,
	0x02c7, 0x02bd, 0x02b2, 0x02a8, 0x029e, 0x0294, 0x028a, 0x0280,
	0x0276, 0x026c, 0x0263, 0x0259, 0x024f, 0x0246, 0x023d, 0x0233,
	0x022a, 0x0221, 0x0218, 0x020f, 0x0206, 0x01fd, 0x01f4, 0x01ec,
	0x01e3, 0x01da, 0x01d2, 0x01c9, 0x01c1, 0x01b9, 0x01b1, 0x01a9,
	0x01a1, 0x0199, 0x0191, 0x0189, 0x0181, 0x017a, 0x0172, 0x016b,
	0x0163, 0x015c, 0x0155, 0x014d, 0x0146, 0x013f, 0x0138, 0x0131,
	0x012b, 0x0124, 0x011d, 0x0117, 0x0110, 0x010a, 0x0103, 0x00fd,
	0x00f7, 0x00f1, 0x00eb, 0x00e5, 0x00df, 0x00d9, 0x00d3, 0x00ce,
	0x00c8, 0x00c3, 0x00bd, 0x00b8, 0x00b3, 0x00ad, 0x00a8, 0x00a3,
	0x009e, 0x0099, 0x0095, 0x0090, 0x008b, 0x0087, 0x0082, 0x007e,
	0x0079, 0x0075, 0x0071, 0x006d, 0x0069, 0x0065, 0x0061, 0x005d,
	0x0059, 0x0056, 0x0052, 0x004f, 0x004b, 0x0048, 0x0044, 0x0041,
	0x003e, 0x003b, 0x0038, 0x0035, 0x0032, 0x0030, 0x002d, 0x002a,
	0x0028, 0x0026, 0x0023, 0x0021, 0x001f, 0x001d, 0x001b, 0x0019,
	0x0017, 0x0015, 0x0013, 0x0011, 0x0010, 0x000e, 0x000d, 0x000c,
	0x000a, 0x0009, 0x0008, 0x0007, 0x0006, 0x0005, 0x0004, 0x0004,
	0x0003, 0x0002, 0x0002, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001,
	0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0002, 0x0002,
	0x0003, 0x0004, 0x0004, 0x0005, 0x0006, 0x0007, 0x0008, 0x0009,
	0x000a, 0x000c, 0x000d, 0x000e, 0x0010, 0x0011, 0x0013, 0x0015,
	0x0017, 0x0019, 0x001b, 0x001d, 0x001f, 0x0021, 0x0023, 0x0026,
	0x0028, 0x002a, 0x002d, 0x0030, 0x0032, 0x0035, 0x0038, 0x003b,
	0x003e, 0x0041, 0x0044, 0x0048, 0x004b, 0x004f, 0x0052, 0x0056,
	0x0059, 0x005d, 0x0061, 0x0065, 0x0069, 0x006d, 0x0071, 0x0075,
	0x0079, 0x007e, 0x0082, 0x0087, 0x008b, 0x0090, 0x0095, 0x0099,
	0x009e, 0x00a3, 0x00a8, 0x00ad, 0x00b3, 0x00b8, 0x00bd, 0x00c3,
	0x00c8, 0x00ce, 0x00d3, 0x00d9, 0x00df, 0x00e5, 0x00eb, 0x00f1,
	0x00f7, 0x00fd, 0x0103, 0x010a, 0x0110, 0x0117, 0x011d, 0x0124,
	0x012b, 0x0131, 0x0138, 0x013f, 0x0146, 0x014d, 0x0155, 0x015c,
	0x0163, 0x016b, 0x0172, 0x017a, 0x0181, 0x0189, 0x0191, 0x0199,
	0x01a1, 0x01a9, 0x01b1, 0x01b9, 0x01c1, 0x01c9, 0x01d2, 0x01da,
	0x01e3, 0x01ec, 0x01f4, 0x01fd, 0x0206, 0x020f, 0x0218, 0x0221,
	0x022a, 0x0233, 0x023d, 0x0246, 0x024f, 0x0259, 0x0263, 0x026c,
	0x0276, 0x0280, 0x028a, 0x0294, 0x029e, 0x02a8, 0x02b2, 0x02bd,
	0x02c7, 0x02d1, 0x02dc, 0x02e7, 0x02f1, 0x02fc, 0x0307, 0x0312,
	0x031d, 0x0328, 0x0333, 0x033e, 0x0349, 0x0355, 0x0360, 0x036c,
	0x0377, 0x0383, 0x038f, 0x039a, 0x03a6, 0x03b2, 0x03be, 0x03ca,
	0x03d6, 0x03e3, 0x03ef, 0x03fb, 0x0408, 0x0414, 0x0421, 0x042e,
	0x043b, 0x0447, 0x0454, 0x0461, 0x046e, 0x047c, 0x0489, 0x0496,
	0x04a3, 0x04b1, 0x04be, 0x04cc, 0x04da, 0x04e7, 0x04f5, 0x0503,
	0x0511, 0x051f, 0x052d, 0x053b, 0x054a, 0x0558, 0x0566, 0x0575,
	0x0583, 0x0592, 0x05a1, 0x05b0, 0x05be, 0x05cd, 0x05dc, 0x05eb,
	0x05fb, 0x060a, 0x0619, 0x0628, 0x0638, 0x0647, 0x0657, 0x0667,
	0x0676, 0x0686, 0x0696, 0x06a6, 0x06b6, 0x06c6, 0x06d6, 0x06e6,
	0x06f7, 0x0707, 0x0718, 0x0728, 0x0739, 0x0749, 0x075a, 0x076b,
	0x077c, 0x078d, 0x079e, 0x07af, 0x07c0, 0x07d1, 0x07e3, 0x07f4,
	0x0806, 0x0817, 0x0829, 0x083b, 0x084c, 0x085e, 0x0870, 0x0882,
	0x0894, 0x08a6, 0x08b8, 0x08cb, 0x08dd, 0x08ef, 0x0902, 0x0915,
	0x0927, 0x093a, 0x094d, 0x095f, 0x0972, 0x0985, 0x0998, 0x09ac,
	0x09bf, 0x09d2, 0x09e5, 0x09f9, 0x0a0c, 0x0a20, 0x0a33, 0x0a47,
	0x0a5b, 0x0a6f, 0x0a83, 0x0a97, 0x0aab, 0x0abf, 0x0ad3, 0x0ae7,
	0x0afc, 0x0b10, 0x0b24, 0x0b39, 0x0b4e, 0x0b62, 0x0b77, 0x0b8c,
	0x0ba1, 0x0bb6, 0x0bcb, 0x0be0, 0x0bf5, 0x0c0a, 0x0c20, 0x0c35,
	0x0c4a, 0x0c60, 0x0c76, 0x0c8b, 0x0ca1, 0x0cb7, 0x0ccd, 0x0ce3,
	0x0cf9, 0x0d0f, 0x0d25, 0x0d3b, 0x0d51, 0x0d68, 0x0d7e, 0x0d95,
	0x0dab, 0x0dc2, 0x0dd9, 0x0def, 0x0e06, 0x0e1d, 0x0e34, 0x0e4b,
	0x0e62, 0x0e79, 0x0e91, 0x0ea8, 0x0ebf, 0x0ed7, 0x0eee, 0x0f06,
	0x0f1e, 0x0f35, 0x0f4d, 0x0f65, 0x0f7d, 0x0f95, 0x0fad, 0x0fc5,
	0x0fdd, 0x0ff6, 0x100e, 0x1026, 0x103f, 0x1057, 0x1070, 0x1089,
	0x10a1, 0x10ba, 0x10d3, 0x10ec, 0x1105, 0x111e, 0x1137, 0x1150,
	0x116a, 0x1183, 0x119c, 0x11b6, 0x11cf, 0x11e9, 0x1203, 0x121c,
	0x1236, 0x1250, 0x126a, 0x1284, 0x129e, 0x12b8, 0x12d3, 0x12ed,
	0x1307, 0x1322, 0x133c, 0x1357, 0x1371, 0x138c, 0x13a7, 0x13c1,
	0x13dc, 0x13f7, 0x1412, 0x142d, 0x1448, 0x1463, 0x147f, 0x149a,
	0x14b5, 0x14d1, 0x14ec, 0x1508, 0x1524, 0x153f, 0x155b, 0x1577,
	0x1593, 0x15af, 0x15cb, 0x15e7, 0x1603, 0x161f, 0x163b, 0x1658,
	0x1674, 0x1691, 0x16ad, 0x16ca, 0x16e6, 0x1703, 0x1720, 0x173d,
	0x175a, 0x1777, 0x1794, 0x17b1, 0x17ce, 0x17eb, 0x1808, 0x1826,
	0x1843, 0x1861, 0x187e, 0x189c, 0x18ba, 0x18d7, 0x18f5, 0x1913,
	0x1931, 0x194f, 0x196d, 0x198b, 0x19a9, 0x19c7, 0x19e6, 0x1a04,
	0x1a22, 0x1a41, 0x1a5f, 0x1a7e, 0x1a9d, 0x1abb, 0x1ada, 0x1af9,
	0x1b18, 0x1b37, 0x1b56, 0x1b75, 0x1b94, 0x1bb3, 0x1bd2, 0x1bf2,
	0x1c11, 0x1c31, 0x1c50, 0x1c70, 0x1c8f, 0x1caf, 0x1ccf, 0x1cee,
	0x1d0e, 0x1d2e, 0x1d4e, 0x1d6e, 0x1d8e, 0x1dae, 0x1dcf, 0x1def,
	0x1e0f, 0x1e30, 0x1e50, 0x1e71, 0x1e91, 0x1eb2, 0x1ed2, 0x1ef3,
	0x1f14, 0x1f35, 0x1f56, 0x1f77, 0x1f98, 0x1fb9, 0x1fda, 0x1ffb,
	0x201d, 0x203e, 0x205f, 0x2081, 0x20a2, 0x20c4, 0x20e5, 0x2107,
	0x2129, 0x214b, 0x216c, 0x218e, 0x21b0, 0x21d2, 0x21f4, 0x2216,
	0x2239, 0x225b, 0x227d, 0x22a0, 0x22c2, 0x22e4, 0x2307, 0x2329,
	0x234c, 0x236f, 0x2392, 0x23b4, 0x23d7, 0x23fa, 0x241d, 0x2440,
	0x2463, 0x2486, 0x24a9, 0x24cd, 0x24f0, 0x2513, 0x2537, 0x255a,
	0x257e, 0x25a1, 0x25c5, 0x25e9, 0x260c, 0x2630, 0x2654, 0x2678,
	0x269c, 0x26c0, 0x26e4, 0x2708, 0x272c, 0x2750, 0x2775, 0x2799,
	0x27bd, 0x27e2, 0x2806, 0x282b, 0x284f, 0x2874, 0x2899, 0x28bd,
	0x28e2, 0x2907, 0x292c, 0x2951, 0x2976, 0x299b, 0x29c0, 0x29e5,
	0x2a0b, 0x2a30, 0x2a55, 0x2a7a, 0x2aa0, 0x2ac5, 0x2aeb, 0x2b10,
	0x2b36, 0x2b5c, 0x2b82, 0x2ba7, 0x2bcd, 0x2bf3, 0x2c19, 0x2c3f,
	0x2c65, 0x2c8b, 0x2cb1, 0x2cd7, 0x2cfe, 0x2d24, 0x2d4a, 0x2d71,
	0x2d97, 0x2dbe, 0x2de4, 0x2e0b, 0x2e31, 0x2e58, 0x2e7f, 0x2ea6,
	0x2ecc, 0x2ef3, 0x2f1a, 0x2f41, 0x2f68, 0x2f8f, 0x2fb6, 0x2fde,
	0x3005, 0x302c, 0x3053, 0x307b, 0x30a2, 0x30ca, 0x30f1, 0x3119,
	0x3140, 0x3168, 0x3190, 0x31b7, 0x31df, 0x3207, 0x322f, 0x3257,
	0x327f, 0x32a7, 0x32cf, 0x32f7, 0x331f, 0x3347, 0x3370, 0x3398,
	0x33c0, 0x33e9, 0x3411, 0x343a, 0x3462, 0x348b, 0x34b3, 0x34dc,
	0x3505, 0x352d, 0x3556, 0x357f, 0x35a8, 0x35d1, 0x35fa, 0x3623,
	0x364c, 0x3675, 0x369e, 0x36c7, 0x36f1, 0x371a, 0x3743, 0x376d,
	0x3796, 0x37c0, 0x37e9, 0x3813, 0x383c, 0x3866, 0x3890, 0x38b9,
	0x38e3, 0x390d, 0x3937, 0x3961, 0x398b, 0x39b5, 0x39df, 0x3a09,
	0x3a33, 0x3a5d, 0x3a87, 0x3ab1, 0x3adc, 0x3b06, 0x3b30, 0x3b5b,
	0x3b85, 0x3bb0, 0x3bda, 0x3c05, 0x3c2f, 0x3c5a, 0x3c85, 0x3caf,
	0x3cda, 0x3d05, 0x3d30, 0x3d5b, 0x3d86, 0x3db1, 0x3ddc, 0x3e07,
	0x3e32, 0x3e5d, 0x3e88, 0x3eb3, 0x3edf, 0x3f0a, 0x3f35, 0x3f61,
	0x3f8c, 0x3fb8, 0x3fe3, 0x400f, 0x403a, 0x4066, 0x4091, 0x40bd,
	0x40e9, 0x4114, 0x4140, 0x416c, 0x4198, 0x41c4, 0x41f0, 0x421c,
	0x4248, 0x4274, 0x42a0, 0x42cc, 0x42f8, 0x4324, 0x4351, 0x437d,
	0x43a9, 0x43d6, 0x4402, 0x442e, 0x445b, 0x4487, 0x44b4, 0x44e0,
	0x450d, 0x453a, 0x4566, 0x4593, 0x45c0, 0x45ed, 0x4619, 0x4646,
	0x4673, 0x46a0, 0x46cd, 0x46fa, 0x4727, 0x4754, 0x4781, 0x47ae,
	0x47db, 0x4809, 0x4836, 0x4863, 0x4890, 0x48be, 0x48eb, 0x4918,
	0x4946, 0x4973, 0x49a1, 0x49ce, 0x49fc, 0x4a29, 0x4a57, 0x4a85,
	0x4ab2, 0x4ae0, 0x4b0e, 0x4b3c, 0x4b69, 0x4b97, 0x4bc5, 0x4bf3,
	0x4c21, 0x4c4f, 0x4c7d, 0x4cab, 0x4cd9, 0x4d07, 0x4d35, 0x4d63,
	0x4d92, 0x4dc0, 0x4dee, 0x4e1c, 0x4e4b, 0x4e79, 0x4ea7, 0x4ed6,
	0x4f04, 0x4f33, 0x4f61, 0x4f90, 0x4fbe, 0x4fed, 0x501b, 0x504a,
	0x5079, 0x50a7, 0x50d6, 0x5105, 0x5133, 0x5162, 0x5191, 0x51c0,
	0x51ef, 0x521e, 0x524d, 0x527c, 0x52ab, 0x52da, 0x5309, 0x5338,
	0x5367, 0x5396, 0x53c5, 0x53f4, 0x5424, 0x5453, 0x5482, 0x54b1,
	0x54e1, 0x5510, 0x553f, 0x556f, 0x559e, 0x55ce, 0x55fd, 0x562d,
	0x565c, 0x568c, 0x56bb, 0x56eb, 0x571a, 0x574a, 0x577a, 0x57a9,
	0x57d9, 0x5809, 0x5839, 0x5868, 0x5898, 0x58c8, 0x58f8, 0x5928,
	0x5958, 0x5988, 0x59b8, 0x59e8, 0x5a18, 0x5a48, 0x5a78, 0x5aa8,
	0x5ad8, 0x5b08, 0x5b38, 0x5b68, 0x5b98, 0x5bc9, 0x5bf9, 0x5c29,
	0x5c59, 0x5c8a, 0x5cba, 0x5cea, 0x5d1b, 0x5d4b, 0x5d7b, 0x5dac,
	0x5ddc, 0x5e0d, 0x5e3d, 0x5e6e, 0x5e9e, 0x5ecf, 0x5eff, 0x5f30,
	0x5f60, 0x5f91, 0x5fc2, 0x5ff2, 0x6023, 0x6054, 0x6084, 0x60b5,
	0x60e6, 0x6117, 0x6147, 0x6178, 0x61a9, 0x61da, 0x620b, 0x623c,
	0x626c, 0x629d, 0x62ce, 0x62ff, 0x6330, 0x6361, 0x6392, 0x63c3,
	0x63f4, 0x6425, 0x6456, 0x6487, 0x64b9, 0x64ea, 0x651b, 0x654c,
	0x657d, 0x65ae, 0x65df, 0x6611, 0x6642, 0x6673, 0x66a4, 0x66d6,
	0x6707, 0x6738, 0x676a, 0x679b, 0x67cc, 0x67fe, 0x682f, 0x6860,
	0x6892, 0x68c3, 0x68f5, 0x6926, 0x6958, 0x6989, 0x69bb, 0x69ec,
	0x6a1e, 0x6a4f, 0x6a81, 0x6ab2, 0x6ae4, 0x6b15, 0x6b47, 0x6b79,
	0x6baa, 0x6bdc, 0x6c0d, 0x6c3f, 0x6c71, 0x6ca2, 0x6cd4, 0x6d06,
	0x6d38, 0x6d69, 0x6d9b, 0x6dcd, 0x6dff, 0x6e30, 0x6e62, 0x6e94,
	0x6ec6, 0x6ef8, 0x6f29, 0x6f5b, 0x6f8d, 0x6fbf, 0x6ff1, 0x7023,
	0x7054, 0x7086, 0x70b8, 0x70ea, 0x711c, 0x714e, 0x7180, 0x71b2,
	0x71e4, 0x7216, 0x7248, 0x727a, 0x72ac, 0x72de, 0x7310, 0x7342,
	0x7374, 0x73a6, 0x73d8, 0x740a, 0x743c, 0x746e, 0x74a0, 0x74d2,
	0x7504, 0x7536, 0x7568, 0x759a, 0x75cd, 0x75ff, 0x7631, 0x7663,
	0x7695, 0x76c7, 0x76f9, 0x772b, 0x775e, 0x7790, 0x77c2, 0x77f4,
	0x7826, 0x7858, 0x788b, 0x78bd, 0x78ef, 0x7921, 0x7953, 0x7985,
	0x79b8, 0x79ea, 0x7a1c, 0x7a4e, 0x7a81, 0x7ab3, 0x7ae5, 0x7b17,
	0x7b49, 0x7b7c, 0x7bae, 0x7be0, 0x7c12, 0x7c45, 0x7c77, 0x7ca9,
	0x7cdb, 0x7d0e, 0x7d40, 0x7d72, 0x7da4, 0x7dd7, 0x7e09, 0x7e3b,
	0x7e6d, 0x7ea0, 0x7ed2, 0x7f04, 0x7f36, 0x7f69, 0x7f9b, 0x7fcd,
};

PROGMEM_DECLARE(uint16_t, PM_SINE[PM_SINE_COUNT]);


/* Linear interpolation with noise */
uint16_t get_interpolated_sine(uint16_t phase)
{
	/* Interpolate result */
	uint16_t left_x       = phase >> 4;												// left side
	int16_t  left_y       = (int16_t)PGM_READ_WORD(&(PM_SINE[left_x])) - 0x8000;
	uint16_t rght_x       = (phase + 16) >> 4;										// right side
	int16_t  rght_y       = (int16_t)PGM_READ_WORD(&(PM_SINE[rght_x])) - 0x8000;
	int16_t  prob         = phase & 0x0f;											// phase fraction
	int16_t  delta_frac_y = (int16_t) (((rght_y - left_y) * prob) >> 4);			// interpolation
	int16_t  val          = left_y + delta_frac_y;

	return 0x8000U + (uint16_t)val;
}
