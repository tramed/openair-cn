/*
 * Licensed to the OpenAirInterface (OAI) Software Alliance under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The OpenAirInterface Software Alliance licenses this file to You under
 * the Apache License, Version 2.0  (the "License"); you may not use this file
 * except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *-------------------------------------------------------------------------------
 * For more information about the OpenAirInterface (OAI) Software Alliance:
 *      contact@openairinterface.org
 */

/*! \file common_types_mbms.c
  \brief
  \author Dincer Beken
  \company blackned GmbH
  \email: dbeken@blackned.de
*/

#ifndef FILE_COMMON_TYPES_MBMS_SEEN
#define FILE_COMMON_TYPES_MBMS_SEEN

#include <arpa/inet.h>
#include "bstrlib.h"
#include "3gpp_36.443.h"
#include "common_types.h"

//------------------------------------------------------------------------------

#define MAX_M2_ENB 256


// MBMS Service IDs
#define MBMS_SERVICE_INDEX_FMT   "%"PRIx32           //*< Combination of TMGI and MBMS Service Area, such that it is unique!
#define INVALID_MBMS_SERVICE_INDEX   0x00000000          // You can pick any value between 0..2^32-1,

/**
 * The value 0 has a special meaning; it shall denote the whole PLMN as the MBMS Service Area and it shall indicate to a receiving
 * RNC/BSS/MCE that all cells reachable by that RNC/BSS/MCE shall be part of the MBMS Service Area.
 */
#define INVALID_MBMS_SERVICE_AREA_ID 0x0000 	         // You can pick any value between 0..2^16-1,
#define INVALID_MBSFN_AREA_ID 			 0x0000 	         // You can pick any value between 0..2^8-1,
#define MBSFN_AREA_ID_FMT					 "0x%"PRIx8
#define MBMS_SERVICE_AREA_ID_FMT	 "0x%"PRIx16
typedef uint64_t                 	 mbms_service_index_t;

#define INVALID_ENB_MBMS_M2AP_ID_KEY UINT32_MAX
#define MCE_MBMS_M2AP_ID_MASK        0xFFFFFF
#define ENB_MBMS_M2AP_ID_MASK        0x00FFFF
#define ENB_MBMS_M2AP_ID_FMT         "%06"PRIx16
#define MCE_MBMS_M2AP_ID_FMT         "%"PRIx32
#define INVALID_MCE_MBMS_M2AP_ID     0xFFFFFF            // You can pick any value between 0..2^24-1,
#define INVALID_ENB_MBMS_M2AP_ID     0xFFFF		         // You can pick any value between 0..2^16-1,

// TMGI
#define TMGI_FMT PLMN_FMT"|%04x"
#define TMGI_ARG(TmGi_PtR) \
  PLMN_ARG(&(TmGi_PtR)->plmn), \
  (TmGi_PtR)->mbms_service_id

/**
 * MBMS related functionalities.
 */
typedef enum {
	ENB_TYPE_NULL,
	 TDD,
	 FDD
} enb_type_e;

typedef enum {
	 BW_1_4 = 6,
	 BW_3 = 15,
	 BW_5 = 25,
	 BW_10 = 50,
	 BW_15 = 75,
	 BW_20 = 100
} enb_bw_e;



////------------------------------------------------------------------------------
//int enb_bands[73] = {
//  ENB_TYPE_NULL = 0,
//	ENB_TYPE_FDD  = 1,
//	ENB_TYPE_FDD  = 2,
//	ENB_TYPE_FDD  = 3,
//	ENB_TYPE_FDD  = 4,
//	ENB_TYPE_FDD  = 5,
//	ENB_TYPE_NULL = 6,
//	ENB_TYPE_FDD  ,
//	ENB_TYPE_FDD,
//	ENB_TYPE_NULL,
//	ENB_TYPE_FDD,
//	ENB_TYPE_FDD,
//	ENB_TYPE_FDD,
//	ENB_TYPE_FDD,
//	ENB_TYPE_FDD,
//	ENB_TYPE_NULL,
//	ENB_TYPE_NULL,
//	ENB_TYPE_FDD,
//	ENB_TYPE_FDD,
//	ENB_TYPE_FDD,
//	ENB_TYPE_FDD,
//	ENB_TYPE_FDD,
//	ENB_TYPE_FDD,
//	ENB_TYPE_NULL,
//	ENB_TYPE_FDD,
//	ENB_TYPE_FDD,
//	ENB_TYPE_FDD,
//	ENB_TYPE_FDD,
//	ENB_TYPE_FDD,
//	ENB_TYPE_FDD,
//	ENB_TYPE_FDD,
//	ENB_TYPE_FDD,
//	ENB_TYPE_FDD,
//	ENB_TYPE_TDD,
//	ENB_TYPE_TDD,
//	ENB_TYPE_TDD,
//	ENB_TYPE_TDD,
//	ENB_TYPE_TDD,
//	ENB_TYPE_TDD,
//	ENB_TYPE_TDD,
//	ENB_TYPE_TDD,
//	ENB_TYPE_TDD,
//	ENB_TYPE_TDD,
//	ENB_TYPE_TDD,
//	ENB_TYPE_TDD,
//	ENB_TYPE_TDD,
//	ENB_TYPE_TDD,
//	ENB_TYPE_TDD,
//	ENB_TYPE_TDD,
//	ENB_TYPE_NULL,
//	ENB_TYPE_NULL,
//	ENB_TYPE_NULL,
//	ENB_TYPE_NULL,
//	ENB_TYPE_NULL,
//	ENB_TYPE_NULL,
//	ENB_TYPE_NULL,
//	ENB_TYPE_NULL,
//	ENB_TYPE_NULL,
//	ENB_TYPE_NULL,
//	ENB_TYPE_NULL,
//	ENB_TYPE_NULL,
//	ENB_TYPE_NULL,
//	ENB_TYPE_NULL,
//	ENB_TYPE_NULL,
//	ENB_TYPE_NULL,
//	ENB_TYPE_FDD,
//
//	ENB_TYPE_FDD,
//	ENB_TYPE_FDD,
//	ENB_TYPE_FDD,
//	ENB_TYPE_FDD,
//	ENB_TYPE_FDD,
//
//	ENB_TYPE_FDD,
//	ENB_TYPE_FDD
//};

#define ENB_BANDS \
X(0,  ENB_TYPE_NULL) \
X(1,  FDD)  \
X(2,  FDD) 	\
X(3,  FDD) 	\
X(4,  FDD) 	\
X(5,  FDD)		 \
X(6,  ENB_TYPE_NULL) 	\
X(7,  FDD) 	\
X(8,  FDD ) 	\
X(9,  ENB_TYPE_NULL) 	\
X(10, ENB_TYPE_NULL) \
X(11, FDD ) \
X(12, FDD ) \
X(13, FDD ) \
X(14, FDD ) \
X(15, ENB_TYPE_NULL) \
X(16, ENB_TYPE_NULL) \
X(17, FDD ) \
X(18, FDD ) \
X(19, FDD ) \
X(20, FDD ) \
X(21, FDD ) \
X(22, ENB_TYPE_NULL) \
X(23, ENB_TYPE_NULL) \
X(24, FDD ) \
X(25, FDD ) \
X(26, FDD ) \
X(27, ENB_TYPE_NULL) \
X(28, FDD ) \
X(29, ENB_TYPE_NULL) \
X(30, FDD ) \
X(31, FDD ) \
X(32, ENB_TYPE_NULL) \
X(33, ENB_TYPE_NULL) \
X(34, TDD ) \
X(35, ENB_TYPE_NULL) \
X(36, ENB_TYPE_NULL) \
X(37, TDD ) \
X(38, TDD ) \
X(39, TDD ) \
X(40, TDD ) \
X(41, TDD ) \
X(42, TDD ) \
X(43, TDD )
//X(ENB_TYPE_TDD) \
//X(ENB_TYPE_TDD) \
//X(ENB_TYPE_TDD) \
//X(ENB_TYPE_TDD) \
//X(ENB_TYPE_TDD) \
//X(ENB_TYPE_NULL) \
//X(ENB_TYPE_NULL) \
//X(ENB_TYPE_NULL) \
//X(ENB_TYPE_NULL) \
//X(ENB_TYPE_NULL) \
//X(ENB_TYPE_NULL) \
//X(ENB_TYPE_NULL) \
//X(ENB_TYPE_NULL) \
//X(ENB_TYPE_NULL) \
//X(ENB_TYPE_NULL) \
//X(ENB_TYPE_NULL) \
//X(ENB_TYPE_NULL) \
//X(ENB_TYPE_NULL) \
//X(ENB_TYPE_NULL) \
//X(ENB_TYPE_NULL) \
//X(ENB_TYPE_NULL) \
//X(ENB_TYPE_FDD) \
//X(ENB_TYPE_FDD) \
//X(ENB_TYPE_FDD) \
//X(ENB_TYPE_FDD) \
//X(ENB_TYPE_FDD) \
//X(ENB_TYPE_FDD) \
//X(ENB_TYPE_FDD) \
//X(ENB_TYPE_FDD)

//-----------------
// todo: the name from an incremented counter?
typedef enum {
#define X(a, b) BAND_##a,
	ENB_BANDS
 #undef X
} enb_band_e;

static inline enb_type_e get_enb_type(enb_band_e enb_band){
	switch(enb_band) {

#define X(a, b) case a: return b;
	ENB_BANDS
#undef X
	default: return ENB_TYPE_NULL;
	}
}

#define FDD_SUBFRAMES  0b0111001110

#define TDD_DL_UL_TYPES \
X(0, 0b0000000000, 0) \
X(1, 0b0000100001, 2) \
X(2, 0b0001100011, 4) \
X(3, 0b0000000111, 3) \
X(4, 0b0000100111, 4) \
X(5, 0b0001100111, 5) \
X(6, 0b0000000001, 1)

//-----------------
// todo: the name from an incremented counter?
typedef enum {
#define X(a, b, c) TDD_DL_UL_##a,
	TDD_DL_UL_TYPES
 #undef X
} enb_tdd_dl_ul_e;

static inline int get_enb_tdd_subframes(enb_tdd_dl_ul_e tdd_dl_ul){
	switch(tdd_dl_ul) {
#define X(a, b, c) case TDD_DL_UL_##a: return b;
	TDD_DL_UL_TYPES
#undef X
	default: return -1;
	}
}

static inline int get_enb_tdd_subframe_size(enb_tdd_dl_ul_e tdd_dl_ul){
	switch(tdd_dl_ul) {
#define X(a, b, c) case TDD_DL_UL_##a: return c;
	TDD_DL_UL_TYPES
#undef X
	default: return -1;
	}
}
static inline enb_type_e get_enb_type(enb_band_e enb_band){
	switch(enb_band) {
#define X(a, b) case a##_##b: return a;
	ENB_BANDS
#undef X
	default: return ENB_TYPE_NULL;
	}
}

typedef struct {
  unsigned seconds;
  unsigned days;
} mbms_session_duration_t;

/**
 * For FDD and TDD 6 SF can be allocated per RF
 */
#define CSA_SF_SINGLE_FRAME 					6
#define CSA_RF_ALLOC_FRAME_THRESHOLD	0.75

typedef enum{
	CSA_ONE_FRAME		=1,
	CSA_FOUR_FRAME	=4
}csa_frame_num_e;

/** Define the CSA period, on which we make per_sec GBR calculations as RF128. */
#define MBMS_CSA_PERIOD_GCS_AS_RF 128
#define CSA_PERIODS \
X(CSA_PERIOD_RF4, 4) \
X(CSA_PERIOD_RF8, 8) \
X(CSA_PERIOD_RF16, 16) \
X(CSA_PERIOD_RF32, 32) \
X(CSA_PERIOD_RF64, 64) \
X(CSA_PERIOD_RF128, 128)

//-----------------
// todo: the name from an incremented counter?
typedef enum {
#define X(a, b) a,
	CSA_PERIODS
#undef X
} csa_period_e;

static inline int get_csa_period_rf(csa_period_e csa_period){
	switch(csa_period) {
#define X(a, b) case a: return b;
	CSA_PERIODS
#undef X
	default: return -1;
	}
}

#define CSA_RF_ALLOC_PERIODS \
X(CSA_RF_ALLOC_PERIOD_RF1, 1) \
X(CSA_RF_ALLOC_PERIOD_RF2, 2) \
X(CSA_RF_ALLOC_PERIOD_RF4, 4) \
X(CSA_RF_ALLOC_PERIOD_RF8, 8) \
X(CSA_RF_ALLOC_PERIOD_RF16, 16) \
X(CSA_RF_ALLOC_PERIOD_RF32, 32)

//-----------------
// todo: the name from an incremented counter?
typedef enum {
#define X(a, b) a,
	CSA_RF_ALLOC_PERIODS
#undef X
} csa_rf_alloc_period_e;

static inline int get_csa_rf_alloc_period_rf(csa_rf_alloc_period_e csa_rf_alloc_period){
	switch(csa_rf_alloc_period) {
#define X(a, b) case a: return b;
	CSA_RF_ALLOC_PERIODS
#undef X
	default: return -1;
	}
}

typedef uint16_t  mbms_service_area_id_t;
typedef uint8_t   mbsfn_area_id_t;

typedef struct {
  /** Value will be used later in search of MBSFN areas, where the capacity will be calculated. */
//  uint8_t local_mbms_area;
  long 		mcch_modif_start_abs_period;
  long 		mcch_modif_stop_abs_period;
}mcch_modification_periods_t;

typedef struct {
  uint8_t  num_service_area;
#define MAX_MBMS_SERVICE_AREA 256
  mbms_service_area_id_t  serviceArea[MAX_MBMS_SERVICE_AREA];
} mbms_service_area_t;

typedef struct mch_s {
	qci_e mch_qci;
	/** Guaranteed bits per seconds!!. */
  bitrate_t total_gbr_dl_bps;
  struct mbms_session_list_s {
#define MAX_MCH_SESSION_LIST 29
    tmgi_t		tmgis[MAX_MCH_SESSION_LIST];
    uint8_t   num_mbms_sessions;
  }mbms_session_list;
  int 			tb_size;
  int 			mch_subframes_per_csa_period;
}mch_t;

typedef struct mchs_s {
	int 		num_mch;
#define MAX_MCH_PER_MBSFN 15
	mch_t   mch_array[MAX_MCH_PER_MBSFN];
  int 		total_subframes_per_csa_period_necessary;
}mchs_t;

typedef struct mbsfn_area_s{
	mbsfn_area_id_t					mbsfn_area_id;
  mbms_service_area_id_t	mbms_service_area_id;

  /** Modification and Repetition Periods. */
  uint16_t								mcch_modif_period_rf;
  uint16_t								mcch_repetition_period_rf;

  /**
   * MBSFN CSA PERIOD and max. CSA pattern.
   * The first CSA pattern [0] is used for scheduling of MCCH (last repetition).
   * Other bits in the last repetition will not be used.
   */
#define CSA_PATTERN_REPETITION_MIN 32
#define MBSFN_AREA_MAX_CSA_PATTERN 8
#define COMMON_CSA_PATTERN				 7
  uint16_t								mbsfn_csa_period_rf;
  /** MBSFN CSA PATTERNS. */
  struct csa_patterns_s {
  	uint8_t total_csa_pattern_offset;
  	/** Just the index of the CSA patterns, without any indication of the offset of CSA patterns. */
  	uint8_t num_csa_pattern;
  	struct csa_pattern_s{
  		union{
  			uint8_t								  mbms_mch_csa_pattern_1rf:6;
  			uint32_t								mbms_mch_csa_pattern_4rf:24;
  		}csa_pattern_sf;
  		csa_frame_num_e				mbms_csa_pattern_rfs;
  		uint8_t								csa_pattern_repetition_period_rf;
  		uint8_t								csa_pattern_offset_rf;
  	}csa_pattern[MBSFN_AREA_MAX_CSA_PATTERN];
  }csa_patterns;

  uint8_t 								mbms_mcch_msi_mcs;
  double								  mch_mcs_enb_factor;
  uint8_t								  mbms_mcch_subframes;
  enb_band_e							m2_enb_band;
  enb_bw_e								m2_enb_bw; 				/**< May differ in band. */
  enb_tdd_dl_ul_e				  enb_tdd_dl_ul_perc;
  bool 										mbms_sf_slots_half;
  uint8_t									mcch_offset_rf;
} mbsfn_area_t;

typedef struct mbsfn_area_cfg_s {
  mbsfn_area_t  mbsfnArea;
  mchs_t				mchs;
}mbsfn_area_cfg_t;

/**
 * This structure is used to calculate the scheduling amongst multiple MBSFN areas.
 */
typedef struct mbsfn_areas_s{
  uint8_t	 				 num_mbsfn_areas_to_be_scheduled;
#define MAX_MBMSFN_AREAS 256
  uint8_t  				 num_mbsfn_areas;
  mbsfn_area_cfg_t mbsfn_area_cfg[MAX_MBMSFN_AREAS];
} mbsfn_areas_t;

typedef struct mbsfn_area_ids_s{
  uint8_t  num_mbsfn_area_ids;
  mbsfn_area_id_t mbsfn_area_id[MAX_MBMSFN_AREAS];
  mbms_service_area_id_t mbms_service_area_id[MAX_MBMSFN_AREAS];
} mbsfn_area_ids_t;

// todo: possible to import this into a macro from the config?
#define MCS_TABLE \
X(QCI_1, 2, 5) \
X(QCI_2, 2, 6) \
X(QCI_3, 3, 7) \
X(QCI_4, 4, 9) \
X(QCI_5, 5, 10) \
X(QCI_6, 6, 11) \
X(QCI_7, 7, 12) \
X(QCI_8, 8, 14) \
X(QCI_9, 9, 15) \
X(QCI_65, 10, 16) \
X(QCI_66, 9, 17) \
X(QCI_69, 10, 18) \
X(QCI_70, 12, 19) \
X(QCI_75, 11, 20) \
X(QCI_79, 12, 25)

static inline int get_qci_mcs(qci_e qci, int enb_factor){
#define X(a, b, c) case a: return (enb_factor * b) < c ? (enb_factor * b) :c;
	switch(qci) {
	MCS_TABLE
	default: return -1;
	}
}
#undef X

#endif /* FILE_COMMON_TYPES_MBMS_SEEN */
