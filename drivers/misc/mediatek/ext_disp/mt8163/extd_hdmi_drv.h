/* --------------------------------------------------------------------------- */

#ifndef EXTD_HDMI_DRV_H
#define     EXTD_HDMI_DRV_H

/* /#include "mtkfb.h" */
#include "external_display.h"
#include "disp_session.h"
#ifdef CONFIG_MTK_INTERNAL_HDMI_SUPPORT
#include "internal_hdmi_drv.h"
#endif

#define MHL_UART_SHARE_PIN

typedef enum {
	STEP1_ENABLE,
	STEP2_GET_STATUS,
	STEP3_START,
	STEP3_SUSPEND,
	STEP_MAX_NUM
} HDMI_FACTORY_MODE_TEST;
#if 0
typedef enum {
	HDMI_MAX_CHANNEL_2 = 0x2,
	HDMI_MAX_CHANNEL_3 = 0x3,
	HDMI_MAX_CHANNEL_4 = 0x4,
	HDMI_MAX_CHANNEL_5 = 0x5,
	HDMI_MAX_CHANNEL_6 = 0x6,
	HDMI_MAX_CHANNEL_7 = 0x7,
	HDMI_MAX_CHANNEL_8 = 0x8,
} AUDIO_MAX_CHANNEL;

typedef enum {
	HDMI_MAX_SAMPLERATE_32 = 0x1,
	HDMI_MAX_SAMPLERATE_44 = 0x2,
	HDMI_MAX_SAMPLERATE_48 = 0x3,
	HDMI_MAX_SAMPLERATE_96 = 0x4,
	HDMI_MAX_SAMPLERATE_192 = 0x5,
} AUDIO_MAX_SAMPLERATE;

typedef enum {
	HDMI_MAX_BITWIDTH_16 = 0x1,
	HDMI_MAX_BITWIDTH_24 = 0x2,
} AUDIO_MAX_BITWIDTH;

typedef enum {
	HDMI_SCALE_ADJUSTMENT_SUPPORT = 0x01,
	HDMI_ONE_RDMA_LIMITATION = 0x02,
	HDMI_PHONE_GPIO_REUSAGE = 0x04,
} HDMI_CAPABILITY;

typedef struct {
	bool is_audio_enabled;
	bool is_video_enabled;
} hdmi_device_status;

typedef struct {
	unsigned long u4Addr;
	unsigned long u4Data;
} hdmi_device_write;

typedef struct {
	unsigned int u4Data1;
	unsigned int u4Data2;
} hdmi_para_setting;

typedef struct {
	unsigned char u1Hdcpkey[287];
} hdmi_hdcp_key;

typedef struct {
	unsigned char u1Hdcpkey[384];
} hdmi_hdcp_drmkey;

typedef struct {
	unsigned char u1sendsltdata[15];
} send_slt_data;

typedef struct _HDMI_EDID_T {
	unsigned int ui4_ntsc_resolution;	/* use EDID_VIDEO_RES_T, there are many resolution */
	unsigned int ui4_pal_resolution;	/* use EDID_VIDEO_RES_T */
	unsigned int ui4_sink_native_ntsc_resolution;
	unsigned int ui4_sink_native_pal_resolution;
	unsigned int ui4_sink_cea_ntsc_resolution;	/* use EDID_VIDEO_RES_T */
	unsigned int ui4_sink_cea_pal_resolution;	/* use EDID_VIDEO_RES_T */
	unsigned int ui4_sink_dtd_ntsc_resolution;	/* use EDID_VIDEO_RES_T */
	unsigned int ui4_sink_dtd_pal_resolution;	/* use EDID_VIDEO_RES_T */
	unsigned int ui4_sink_1st_dtd_ntsc_resolution;	/* use EDID_VIDEO_RES_T */
	unsigned int ui4_sink_1st_dtd_pal_resolution;	/* use EDID_VIDEO_RES_T */
	unsigned short ui2_sink_colorimetry;	/* use EDID_VIDEO_COLORIMETRY_T */
	unsigned char ui1_sink_rgb_color_bit;	/* color bit for RGB */
	unsigned char ui1_sink_ycbcr_color_bit;	/* color bit for YCbCr */
	unsigned short ui2_sink_aud_dec;	/* use EDID_AUDIO_DECODER_T */
	unsigned char ui1_sink_is_plug_in;	/* 1: Plug in 0:Plug Out */
	unsigned int ui4_hdmi_pcm_ch_type;	/* use EDID_A_FMT_CH_TYPE */
	unsigned int ui4_hdmi_pcm_ch3ch4ch5ch7_type;	/* use EDID_A_FMT_CH_TYPE1 */
	unsigned int ui4_dac_pcm_ch_type;	/* use EDID_A_FMT_CH_TYPE */
	unsigned char ui1_sink_i_latency_present;
	unsigned char ui1_sink_p_audio_latency;
	unsigned char ui1_sink_p_video_latency;
	unsigned char ui1_sink_i_audio_latency;
	unsigned char ui1_sink_i_video_latency;
	unsigned char ui1ExtEdid_Revision;
	unsigned char ui1Edid_Version;
	unsigned char ui1Edid_Revision;
	unsigned char ui1_Display_Horizontal_Size;
	unsigned char ui1_Display_Vertical_Size;
	unsigned int ui4_ID_Serial_Number;
	unsigned int ui4_sink_cea_3D_resolution;
	unsigned char ui1_sink_support_ai;	/* 0: not support AI, 1:support AI */
	unsigned short ui2_sink_cec_address;
	unsigned short ui1_sink_max_tmds_clock;
	unsigned short ui2_sink_3D_structure;
	unsigned int ui4_sink_cea_FP_SUP_3D_resolution;
	unsigned int ui4_sink_cea_TOB_SUP_3D_resolution;
	unsigned int ui4_sink_cea_SBS_SUP_3D_resolution;
	unsigned short ui2_sink_ID_manufacturer_name;	/* (08H~09H) */
	unsigned short ui2_sink_ID_product_code;	/* (0aH~0bH) */
	unsigned int ui4_sink_ID_serial_number;	/* (0cH~0fH) */
	unsigned char ui1_sink_week_of_manufacture;	/* (10H) */
	unsigned char ui1_sink_year_of_manufacture;	/* (11H)  base on year 1990 */
} HDMI_EDID_T;

typedef struct {
	unsigned int ui4_sink_FP_SUP_3D_resolution;
	unsigned int ui4_sink_TOB_SUP_3D_resolution;
	unsigned int ui4_sink_SBS_SUP_3D_resolution;
} MHL_3D_SUPP_T;

typedef struct {
	unsigned char ui1_la_num;
	unsigned char e_la[3];
	unsigned short ui2_pa;
	unsigned short h_cecm_svc;
} CEC_DRV_ADDR_CFG;

typedef struct {
	unsigned char destination:4;
	unsigned char initiator:4;
} CEC_HEADER_BLOCK_IO;

typedef struct {
	CEC_HEADER_BLOCK_IO header;
	unsigned char opcode;
	unsigned char operand[15];
} CEC_FRAME_BLOCK_IO;

typedef struct {
	unsigned char size;
	unsigned char sendidx;
	unsigned char reTXcnt;
	void *txtag;
	CEC_FRAME_BLOCK_IO blocks;
} CEC_FRAME_DESCRIPTION_IO;

typedef struct _CEC_FRAME_INFO {
	unsigned char ui1_init_addr;
	unsigned char ui1_dest_addr;
	unsigned short ui2_opcode;
	unsigned char aui1_operand[14];
	unsigned int z_operand_size;
} CEC_FRAME_INFO;

typedef struct _CEC_SEND_MSG {
	CEC_FRAME_INFO t_frame_info;
	unsigned char b_enqueue_ok;
} CEC_SEND_MSG;

typedef struct {
	unsigned char ui1_la;
	unsigned short ui2_pa;
} CEC_ADDRESS_IO;

typedef struct {
	unsigned char u1Size;
	unsigned char au1Data[14];
} CEC_GETSLT_DATA;

typedef struct {
	unsigned int u1address;
	unsigned int pu1Data;
} READ_REG_VALUE;

typedef struct {
	unsigned char e_hdmi_aud_in;
	unsigned char e_iec_frame;
	unsigned char e_hdmi_fs;
	unsigned char e_aud_code;
	unsigned char u1Aud_Input_Chan_Cnt;
	unsigned char e_I2sFmt;
	unsigned char u1HdmiI2sMclk;
	unsigned char bhdmi_LCh_status[5];
	unsigned char bhdmi_RCh_status[5];
} HDMITX_AUDIO_PARA;
#endif
/* ~~~~~~~~~~~~~~~~~~~~~~~~extern declare~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
#ifdef EXTD_DBG_USE_INNER_BUF
extern unsigned char kara_1280x720[2764800];
#endif

extern int ovl1_remove;

extern void HDMI_DBG_Init(void);
extern const struct HDMI_DRIVER *HDMI_GetDriver(void);
extern unsigned long get_dim_layer_mva_addr(void);
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */


/*the following APIs are for MHL control*/
void hdmi_resume(void);
void hdmi_suspend(void);
int hdmi_video_config(HDMI_VIDEO_RESOLUTION vformat, enum HDMI_VIDEO_INPUT_FORMAT vin,
		      enum HDMI_VIDEO_OUTPUT_FORMAT vout);
bool is_hdmi_active(void);

void hdmi_enable(int enable);
void hdmi_power_enable(int enable);
void hdmi_force_disable(int enable);
void hdmi_force_on(int enable);
bool is_hdmi_active(void);
void hdmi_set_USBOTG_status(int status);
void hdmi_set_audio_enable(int enable);
void hdmi_set_video_enable(int enable);
void hdmi_set_resolution(int res);
void hdmi_init(void);
void hdmi_set_layer_num(int layer_num);
int hdmi_get_dev_info(void *info);
int hdmi_get_capability(void *info);
int hdmi_get_edid(void *edid_info);
int hdmi_screen_capture(void *info);
int hdmi_is_force_awake(void *argp);
int hdmi_factory_mode_test(HDMI_FACTORY_MODE_TEST test_step, void *info);

void extd_hdmi_path_init(EXT_DISP_PATH_MODE mode, int session);
void extd_hdmi_path_deinit(void);
void extd_hdmi_path_resume(void);
void extd_hdmi_path_set_mode(EXT_DISP_PATH_MODE mode);
int extd_hdmi_trigger(int blocking, void *callback, unsigned int session);
int extd_hdmi_config_input_multiple(ext_disp_input_config *input, int idx);
int extd_hdmi_get_dev_info(void *info);
int extd_get_path_handle(disp_path_handle *dp_handle, cmdqRecHandle *pHandle);
int extd_get_device_type(void);
EXT_DISP_PATH_MODE extd_hdmi_path_get_mode(void);

void hdmi_cable_fake_plug_in(void);
void hdmi_cable_fake_plug_out(void);
#if (defined(CONFIG_MTK_IN_HOUSE_TEE_SUPPORT) && defined(CONFIG_MTK_HDMI_HDCP_SUPPORT) \
	&& defined(CONFIG_MTK_DRM_KEY_MNG_SUPPORT))
void hdmi_install_hdcpkey(hdmi_hdcp_drmkey *key);
#else
void hdmi_install_hdcpkey(hdmi_hdcp_key *key);
#endif

int hdmi_recompute_bg(int src_w, int src_h);

void hdmi_read_reg(READ_REG_VALUE *reg_val);
void hdmi_write_reg(hdmi_device_write regval);
bool hdmi_is_debug_output(void);

void hdmi_config_pll(unsigned long resolutionmode);
void dpi_setting_res(unsigned long arg);
void hdmi_set_colordeep(unsigned int colorspace, unsigned int deep);
void hdmi_set_audio_param(HDMITX_AUDIO_PARA *audio_param);

void hdmi_cable_fake_plug_out(void);
void hdmi_log_enable(int enable);
void hdmi_cable_fake_plug_in(void);
void hdmi_cable_fake_plug_out(void);
void hdmi_mmp_enable(int enable);
void hdmi_hwc_enable(int enable);


extern void hdmi_force_on(int from_uart_drv);




#endif
