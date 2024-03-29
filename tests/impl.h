#ifndef SSE2RVV_TEST_H
#define SSE2RVV_TEST_H

#include "common.h"
#include "debug_tools.h"

#define INTRIN_LIST                                                            \
  /* MMX */                                                                    \
  _(mm_empty)                                                                  \
  /* SSE */                                                                    \
  _(mm_add_ps)                                                                 \
  _(mm_add_ss)                                                                 \
  _(mm_and_ps)                                                                 \
  _(mm_andnot_ps)                                                              \
  _(mm_avg_pu16)                                                               \
  _(mm_avg_pu8)                                                                \
  _(mm_cmpeq_ps)                                                               \
  _(mm_cmpeq_ss)                                                               \
  _(mm_cmpge_ps)                                                               \
  _(mm_cmpge_ss)                                                               \
  _(mm_cmpgt_ps)                                                               \
  _(mm_cmpgt_ss)                                                               \
  _(mm_cmple_ps)                                                               \
  _(mm_cmple_ss)                                                               \
  _(mm_cmplt_ps)                                                               \
  _(mm_cmplt_ss)                                                               \
  _(mm_cmpneq_ps)                                                              \
  _(mm_cmpneq_ss)                                                              \
  _(mm_cmpnge_ps)                                                              \
  _(mm_cmpnge_ss)                                                              \
  _(mm_cmpngt_ps)                                                              \
  _(mm_cmpngt_ss)                                                              \
  _(mm_cmpnle_ps)                                                              \
  _(mm_cmpnle_ss)                                                              \
  _(mm_cmpnlt_ps)                                                              \
  _(mm_cmpnlt_ss)                                                              \
  _(mm_cmpord_ps)                                                              \
  _(mm_cmpord_ss)                                                              \
  _(mm_cmpunord_ps)                                                            \
  _(mm_cmpunord_ss)                                                            \
  _(mm_comieq_ss)                                                              \
  _(mm_comige_ss)                                                              \
  _(mm_comigt_ss)                                                              \
  _(mm_comile_ss)                                                              \
  _(mm_comilt_ss)                                                              \
  _(mm_comineq_ss)                                                             \
  _(mm_cvt_pi2ps)                                                              \
  _(mm_cvt_ps2pi)                                                              \
  _(mm_cvt_si2ss)                                                              \
  _(mm_cvt_ss2si)                                                              \
  _(mm_cvtpi16_ps)                                                             \
  _(mm_cvtpi32_ps)                                                             \
  _(mm_cvtpi32x2_ps)                                                           \
  _(mm_cvtpi8_ps)                                                              \
  _(mm_cvtps_pi16)                                                             \
  _(mm_cvtps_pi32)                                                             \
  _(mm_cvtps_pi8)                                                              \
  _(mm_cvtpu16_ps)                                                             \
  _(mm_cvtpu8_ps)                                                              \
  _(mm_cvtsi32_ss)                                                             \
  _(mm_cvtsi64_ss)                                                             \
  _(mm_cvtss_f32)                                                              \
  _(mm_cvtss_si32)                                                             \
  _(mm_cvtss_si64)                                                             \
  _(mm_cvtt_ps2pi)                                                             \
  _(mm_cvtt_ss2si)                                                             \
  _(mm_cvttps_pi32)                                                            \
  _(mm_cvttss_si32)                                                            \
  _(mm_cvttss_si64)                                                            \
  _(mm_div_ps)                                                                 \
  _(mm_div_ss)                                                                 \
  _(mm_extract_pi16)                                                           \
  _(mm_free)                                                                   \
  _(mm_get_flush_zero_mode)                                                    \
  _(mm_get_rounding_mode)                                                      \
  _(mm_getcsr)                                                                 \
  _(mm_insert_pi16)                                                            \
  _(mm_load_ps)                                                                \
  _(mm_load_ps1)                                                               \
  _(mm_load_ss)                                                                \
  _(mm_load1_ps)                                                               \
  _(mm_loadh_pi)                                                               \
  _(mm_loadl_pi)                                                               \
  _(mm_loadr_ps)                                                               \
  _(mm_loadu_ps)                                                               \
  _(mm_loadu_si16)                                                             \
  _(mm_loadu_si64)                                                             \
  _(mm_malloc)                                                                 \
  _(mm_maskmove_si64)                                                          \
  _(m_maskmovq)                                                                \
  _(mm_max_pi16)                                                               \
  _(mm_max_ps)                                                                 \
  _(mm_max_pu8)                                                                \
  _(mm_max_ss)                                                                 \
  _(mm_min_pi16)                                                               \
  _(mm_min_ps)                                                                 \
  _(mm_min_pu8)                                                                \
  _(mm_min_ss)                                                                 \
  _(mm_move_ss)                                                                \
  _(mm_movehl_ps)                                                              \
  _(mm_movelh_ps)                                                              \
  _(mm_movemask_pi8)                                                           \
  _(mm_movemask_ps)                                                            \
  _(mm_mul_ps)                                                                 \
  _(mm_mul_ss)                                                                 \
  _(mm_mulhi_pu16)                                                             \
  _(mm_or_ps)                                                                  \
  _(m_pavgb)                                                                   \
  _(m_pavgw)                                                                   \
  _(m_pextrw)                                                                  \
  _(m_pinsrw)                                                                  \
  _(m_pmaxsw)                                                                  \
  _(m_pmaxub)                                                                  \
  _(m_pminsw)                                                                  \
  _(m_pminub)                                                                  \
  _(m_pmovmskb)                                                                \
  _(m_pmulhuw)                                                                 \
  _(mm_prefetch)                                                               \
  _(m_psadbw)                                                                  \
  _(m_pshufw)                                                                  \
  _(mm_rcp_ps)                                                                 \
  _(mm_rcp_ss)                                                                 \
  _(mm_rsqrt_ps)                                                               \
  _(mm_rsqrt_ss)                                                               \
  _(mm_sad_pu8)                                                                \
  _(mm_set_flush_zero_mode)                                                    \
  _(mm_set_ps)                                                                 \
  _(mm_set_ps1)                                                                \
  _(mm_set_rounding_mode)                                                      \
  _(mm_set_ss)                                                                 \
  _(mm_set1_ps)                                                                \
  _(mm_setcsr)                                                                 \
  _(mm_setr_ps)                                                                \
  _(mm_setzero_ps)                                                             \
  _(mm_sfence)                                                                 \
  _(mm_shuffle_pi16)                                                           \
  _(mm_shuffle_ps)                                                             \
  _(mm_sqrt_ps)                                                                \
  _(mm_sqrt_ss)                                                                \
  _(mm_store_ps)                                                               \
  _(mm_store_ps1)                                                              \
  _(mm_store_ss)                                                               \
  _(mm_store1_ps)                                                              \
  _(mm_storeh_pi)                                                              \
  _(mm_storel_pi)                                                              \
  _(mm_storer_ps)                                                              \
  _(mm_storeu_ps)                                                              \
  _(mm_storeu_si16)                                                            \
  _(mm_storeu_si64)                                                            \
  _(mm_stream_pi)                                                              \
  _(mm_stream_ps)                                                              \
  _(mm_sub_ps)                                                                 \
  _(mm_sub_ss)                                                                 \
  _(mm_ucomieq_ss)                                                             \
  _(mm_ucomige_ss)                                                             \
  _(mm_ucomigt_ss)                                                             \
  _(mm_ucomile_ss)                                                             \
  _(mm_ucomilt_ss)                                                             \
  _(mm_ucomineq_ss)                                                            \
  _(mm_undefined_ps)                                                           \
  _(mm_unpackhi_ps)                                                            \
  _(mm_unpacklo_ps)                                                            \
  _(mm_xor_ps)                                                                 \
  /* SSE2 */                                                                   \
  _(mm_add_epi16)                                                              \
  _(mm_add_epi32)                                                              \
  _(mm_add_epi64)                                                              \
  _(mm_add_epi8)                                                               \
  _(mm_add_pd)                                                                 \
  _(mm_add_sd)                                                                 \
  _(mm_add_si64)                                                               \
  _(mm_adds_epi16)                                                             \
  _(mm_adds_epi8)                                                              \
  _(mm_adds_epu16)                                                             \
  _(mm_adds_epu8)                                                              \
  _(mm_and_pd)                                                                 \
  _(mm_and_si128)                                                              \
  _(mm_andnot_pd)                                                              \
  _(mm_andnot_si128)                                                           \
  _(mm_avg_epu16)                                                              \
  _(mm_avg_epu8)                                                               \
  _(mm_bslli_si128)                                                            \
  _(mm_bsrli_si128)                                                            \
  _(mm_castpd_ps)                                                              \
  _(mm_castpd_si128)                                                           \
  _(mm_castps_pd)                                                              \
  _(mm_castps_si128)                                                           \
  _(mm_castsi128_pd)                                                           \
  _(mm_castsi128_ps)                                                           \
  _(mm_clflush)                                                                \
  _(mm_cmpeq_epi16)                                                            \
  _(mm_cmpeq_epi32)                                                            \
  _(mm_cmpeq_epi8)                                                             \
  _(mm_cmpeq_pd)                                                               \
  _(mm_cmpeq_sd)                                                               \
  _(mm_cmpge_pd)                                                               \
  _(mm_cmpge_sd)                                                               \
  _(mm_cmpgt_epi16)                                                            \
  _(mm_cmpgt_epi32)                                                            \
  _(mm_cmpgt_epi8)                                                             \
  _(mm_cmpgt_pd)                                                               \
  _(mm_cmpgt_sd)                                                               \
  _(mm_cmple_pd)                                                               \
  _(mm_cmple_sd)                                                               \
  _(mm_cmplt_epi16)                                                            \
  _(mm_cmplt_epi32)                                                            \
  _(mm_cmplt_epi8)                                                             \
  _(mm_cmplt_pd)                                                               \
  _(mm_cmplt_sd)                                                               \
  _(mm_cmpneq_pd)                                                              \
  _(mm_cmpneq_sd)                                                              \
  _(mm_cmpnge_pd)                                                              \
  _(mm_cmpnge_sd)                                                              \
  _(mm_cmpngt_pd)                                                              \
  _(mm_cmpngt_sd)                                                              \
  _(mm_cmpnle_pd)                                                              \
  _(mm_cmpnle_sd)                                                              \
  _(mm_cmpnlt_pd)                                                              \
  _(mm_cmpnlt_sd)                                                              \
  _(mm_cmpord_pd)                                                              \
  _(mm_cmpord_sd)                                                              \
  _(mm_cmpunord_pd)                                                            \
  _(mm_cmpunord_sd)                                                            \
  _(mm_comieq_sd)                                                              \
  _(mm_comige_sd)                                                              \
  _(mm_comigt_sd)                                                              \
  _(mm_comile_sd)                                                              \
  _(mm_comilt_sd)                                                              \
  _(mm_comineq_sd)                                                             \
  _(mm_cvtepi32_pd)                                                            \
  _(mm_cvtepi32_ps)                                                            \
  _(mm_cvtpd_epi32)                                                            \
  _(mm_cvtpd_pi32)                                                             \
  _(mm_cvtpd_ps)                                                               \
  _(mm_cvtpi32_pd)                                                             \
  _(mm_cvtps_epi32)                                                            \
  _(mm_cvtps_pd)                                                               \
  _(mm_cvtsd_f64)                                                              \
  _(mm_cvtsd_si32)                                                             \
  _(mm_cvtsd_si64)                                                             \
  _(mm_cvtsd_si64x)                                                            \
  _(mm_cvtsd_ss)                                                               \
  _(mm_cvtsi128_si32)                                                          \
  _(mm_cvtsi128_si64)                                                          \
  _(mm_cvtsi128_si64x)                                                         \
  _(mm_cvtsi32_sd)                                                             \
  _(mm_cvtsi32_si128)                                                          \
  _(mm_cvtsi64_sd)                                                             \
  _(mm_cvtsi64_si128)                                                          \
  _(mm_cvtsi64x_sd)                                                            \
  _(mm_cvtsi64x_si128)                                                         \
  _(mm_cvtss_sd)                                                               \
  _(mm_cvttpd_epi32)                                                           \
  _(mm_cvttpd_pi32)                                                            \
  _(mm_cvttps_epi32)                                                           \
  _(mm_cvttsd_si32)                                                            \
  _(mm_cvttsd_si64)                                                            \
  _(mm_cvttsd_si64x)                                                           \
  _(mm_div_pd)                                                                 \
  _(mm_div_sd)                                                                 \
  _(mm_extract_epi16)                                                          \
  _(mm_insert_epi16)                                                           \
  _(mm_lfence)                                                                 \
  _(mm_load_pd)                                                                \
  _(mm_load_pd1)                                                               \
  _(mm_load_sd)                                                                \
  _(mm_load_si128)                                                             \
  _(mm_load1_pd)                                                               \
  _(mm_loadh_pd)                                                               \
  _(mm_loadl_epi64)                                                            \
  _(mm_loadl_pd)                                                               \
  _(mm_loadr_pd)                                                               \
  _(mm_loadu_pd)                                                               \
  _(mm_loadu_si128)                                                            \
  _(mm_loadu_si32)                                                             \
  _(mm_madd_epi16)                                                             \
  _(mm_maskmoveu_si128)                                                        \
  _(mm_max_epi16)                                                              \
  _(mm_max_epu8)                                                               \
  _(mm_max_pd)                                                                 \
  _(mm_max_sd)                                                                 \
  _(mm_mfence)                                                                 \
  _(mm_min_epi16)                                                              \
  _(mm_min_epu8)                                                               \
  _(mm_min_pd)                                                                 \
  _(mm_min_sd)                                                                 \
  _(mm_move_epi64)                                                             \
  _(mm_move_sd)                                                                \
  _(mm_movemask_epi8)                                                          \
  _(mm_movemask_pd)                                                            \
  _(mm_movepi64_pi64)                                                          \
  _(mm_movpi64_epi64)                                                          \
  _(mm_mul_epu32)                                                              \
  _(mm_mul_pd)                                                                 \
  _(mm_mul_sd)                                                                 \
  _(mm_mul_su32)                                                               \
  _(mm_mulhi_epi16)                                                            \
  _(mm_mulhi_epu16)                                                            \
  _(mm_mullo_epi16)                                                            \
  _(mm_or_pd)                                                                  \
  _(mm_or_si128)                                                               \
  _(mm_packs_epi16)                                                            \
  _(mm_packs_epi32)                                                            \
  _(mm_packus_epi16)                                                           \
  _(mm_pause)                                                                  \
  _(mm_sad_epu8)                                                               \
  _(mm_set_epi16)                                                              \
  _(mm_set_epi32)                                                              \
  _(mm_set_epi64)                                                              \
  _(mm_set_epi64x)                                                             \
  _(mm_set_epi8)                                                               \
  _(mm_set_pd)                                                                 \
  _(mm_set_pd1)                                                                \
  _(mm_set_sd)                                                                 \
  _(mm_set1_epi16)                                                             \
  _(mm_set1_epi32)                                                             \
  _(mm_set1_epi64)                                                             \
  _(mm_set1_epi64x)                                                            \
  _(mm_set1_epi8)                                                              \
  _(mm_set1_pd)                                                                \
  _(mm_setr_epi16)                                                             \
  _(mm_setr_epi32)                                                             \
  _(mm_setr_epi64)                                                             \
  _(mm_setr_epi8)                                                              \
  _(mm_setr_pd)                                                                \
  _(mm_setzero_pd)                                                             \
  _(mm_setzero_si128)                                                          \
  _(mm_shuffle_epi32)                                                          \
  _(mm_shuffle_pd)                                                             \
  _(mm_shufflehi_epi16)                                                        \
  _(mm_shufflelo_epi16)                                                        \
  _(mm_sll_epi16)                                                              \
  _(mm_sll_epi32)                                                              \
  _(mm_sll_epi64)                                                              \
  _(mm_slli_epi16)                                                             \
  _(mm_slli_epi32)                                                             \
  _(mm_slli_epi64)                                                             \
  _(mm_slli_si128)                                                             \
  _(mm_sqrt_pd)                                                                \
  _(mm_sqrt_sd)                                                                \
  _(mm_sra_epi16)                                                              \
  _(mm_sra_epi32)                                                              \
  _(mm_srai_epi16)                                                             \
  _(mm_srai_epi32)                                                             \
  _(mm_srl_epi16)                                                              \
  _(mm_srl_epi32)                                                              \
  _(mm_srl_epi64)                                                              \
  _(mm_srli_epi16)                                                             \
  _(mm_srli_epi32)                                                             \
  _(mm_srli_epi64)                                                             \
  _(mm_srli_si128)                                                             \
  _(mm_store_pd)                                                               \
  _(mm_store_pd1)                                                              \
  _(mm_store_sd)                                                               \
  _(mm_store_si128)                                                            \
  _(mm_store1_pd)                                                              \
  _(mm_storeh_pd)                                                              \
  _(mm_storel_epi64)                                                           \
  _(mm_storel_pd)                                                              \
  _(mm_storer_pd)                                                              \
  _(mm_storeu_pd)                                                              \
  _(mm_storeu_si128)                                                           \
  _(mm_storeu_si32)                                                            \
  _(mm_stream_pd)                                                              \
  _(mm_stream_si128)                                                           \
  _(mm_stream_si32)                                                            \
  _(mm_stream_si64)                                                            \
  _(mm_sub_epi16)                                                              \
  _(mm_sub_epi32)                                                              \
  _(mm_sub_epi64)                                                              \
  _(mm_sub_epi8)                                                               \
  _(mm_sub_pd)                                                                 \
  _(mm_sub_sd)                                                                 \
  _(mm_sub_si64)                                                               \
  _(mm_subs_epi16)                                                             \
  _(mm_subs_epi8)                                                              \
  _(mm_subs_epu16)                                                             \
  _(mm_subs_epu8)                                                              \
  _(mm_ucomieq_sd)                                                             \
  _(mm_ucomige_sd)                                                             \
  _(mm_ucomigt_sd)                                                             \
  _(mm_ucomile_sd)                                                             \
  _(mm_ucomilt_sd)                                                             \
  _(mm_ucomineq_sd)                                                            \
  _(mm_undefined_pd)                                                           \
  _(mm_undefined_si128)                                                        \
  _(mm_unpackhi_epi16)                                                         \
  _(mm_unpackhi_epi32)                                                         \
  _(mm_unpackhi_epi64)                                                         \
  _(mm_unpackhi_epi8)                                                          \
  _(mm_unpackhi_pd)                                                            \
  _(mm_unpacklo_epi16)                                                         \
  _(mm_unpacklo_epi32)                                                         \
  _(mm_unpacklo_epi64)                                                         \
  _(mm_unpacklo_epi8)                                                          \
  _(mm_unpacklo_pd)                                                            \
  _(mm_xor_pd)                                                                 \
  _(mm_xor_si128)                                                              \
  /* SSE3 */                                                                   \
  _(mm_addsub_pd)                                                              \
  _(mm_addsub_ps)                                                              \
  _(mm_hadd_pd)                                                                \
  _(mm_hadd_ps)                                                                \
  _(mm_hsub_pd)                                                                \
  _(mm_hsub_ps)                                                                \
  _(mm_lddqu_si128)                                                            \
  _(mm_loaddup_pd)                                                             \
  _(mm_movedup_pd)                                                             \
  _(mm_movehdup_ps)                                                            \
  _(mm_moveldup_ps)                                                            \
  /* SSSE3 */                                                                  \
  _(mm_abs_epi16)                                                              \
  _(mm_abs_epi32)                                                              \
  _(mm_abs_epi8)                                                               \
  _(mm_abs_pi16)                                                               \
  _(mm_abs_pi32)                                                               \
  _(mm_abs_pi8)                                                                \
  _(mm_alignr_epi8)                                                            \
  _(mm_alignr_pi8)                                                             \
  _(mm_hadd_epi16)                                                             \
  _(mm_hadd_epi32)                                                             \
  _(mm_hadd_pi16)                                                              \
  _(mm_hadd_pi32)                                                              \
  _(mm_hadds_epi16)                                                            \
  _(mm_hadds_pi16)                                                             \
  _(mm_hsub_epi16)                                                             \
  _(mm_hsub_epi32)                                                             \
  _(mm_hsub_pi16)                                                              \
  _(mm_hsub_pi32)                                                              \
  _(mm_hsubs_epi16)                                                            \
  _(mm_hsubs_pi16)                                                             \
  _(mm_maddubs_epi16)                                                          \
  _(mm_maddubs_pi16)                                                           \
  _(mm_mulhrs_epi16)                                                           \
  _(mm_mulhrs_pi16)                                                            \
  _(mm_shuffle_epi8)                                                           \
  _(mm_shuffle_pi8)                                                            \
  _(mm_sign_epi16)                                                             \
  _(mm_sign_epi32)                                                             \
  _(mm_sign_epi8)                                                              \
  _(mm_sign_pi16)                                                              \
  _(mm_sign_pi32)                                                              \
  _(mm_sign_pi8)                                                               \
  /* SSE4.1 */                                                                 \
  _(mm_blend_epi16)                                                            \
  _(mm_blend_pd)                                                               \
  _(mm_blend_ps)                                                               \
  _(mm_blendv_epi8)                                                            \
  _(mm_blendv_pd)                                                              \
  _(mm_blendv_ps)                                                              \
  _(mm_ceil_pd)                                                                \
  _(mm_ceil_ps)                                                                \
  _(mm_ceil_sd)                                                                \
  _(mm_ceil_ss)                                                                \
  _(mm_cmpeq_epi64)                                                            \
  _(mm_cvtepi16_epi32)                                                         \
  _(mm_cvtepi16_epi64)                                                         \
  _(mm_cvtepi32_epi64)                                                         \
  _(mm_cvtepi8_epi16)                                                          \
  _(mm_cvtepi8_epi32)                                                          \
  _(mm_cvtepi8_epi64)                                                          \
  _(mm_cvtepu16_epi32)                                                         \
  _(mm_cvtepu16_epi64)                                                         \
  _(mm_cvtepu32_epi64)                                                         \
  _(mm_cvtepu8_epi16)                                                          \
  _(mm_cvtepu8_epi32)                                                          \
  _(mm_cvtepu8_epi64)                                                          \
  _(mm_dp_pd)                                                                  \
  _(mm_dp_ps)                                                                  \
  _(mm_extract_epi32)                                                          \
  _(mm_extract_epi64)                                                          \
  _(mm_extract_epi8)                                                           \
  _(mm_extract_ps)                                                             \
  _(mm_floor_pd)                                                               \
  _(mm_floor_ps)                                                               \
  _(mm_floor_sd)                                                               \
  _(mm_floor_ss)                                                               \
  _(mm_insert_epi32)                                                           \
  _(mm_insert_epi64)                                                           \
  _(mm_insert_epi8)                                                            \
  _(mm_insert_ps)                                                              \
  _(mm_max_epi32)                                                              \
  _(mm_max_epi8)                                                               \
  _(mm_max_epu16)                                                              \
  _(mm_max_epu32)                                                              \
  _(mm_min_epi32)                                                              \
  _(mm_min_epi8)                                                               \
  _(mm_min_epu16)                                                              \
  _(mm_min_epu32)                                                              \
  _(mm_minpos_epu16)                                                           \
  _(mm_mpsadbw_epu8)                                                           \
  _(mm_mul_epi32)                                                              \
  _(mm_mullo_epi32)                                                            \
  _(mm_packus_epi32)                                                           \
  _(mm_round_pd)                                                               \
  _(mm_round_ps)                                                               \
  _(mm_round_sd)                                                               \
  _(mm_round_ss)                                                               \
  _(mm_stream_load_si128)                                                      \
  _(mm_test_all_ones)                                                          \
  _(mm_test_all_zeros)                                                         \
  _(mm_test_mix_ones_zeros)                                                    \
  _(mm_testc_si128)                                                            \
  _(mm_testnzc_si128)                                                          \
  _(mm_testz_si128)                                                            \
  /* SSE4.2 */                                                                 \
  /*_(mm_cmpestra)*/                                                           \
  /*_(mm_cmpestrc) */                                                          \
  /*_(mm_cmpestri) */                                                          \
  /*_(mm_cmpestrm) */                                                          \
  /*_(mm_cmpestro) */                                                          \
  /*_(mm_cmpestrs) */                                                          \
  /*_(mm_cmpestrz) */                                                          \
  /*_(mm_cmpgt_epi64) */                                                       \
  /*_(mm_cmpistra) */                                                          \
  /*_(mm_cmpistrc) */                                                          \
  /*_(mm_cmpistri) */                                                          \
  /*_(mm_cmpistrm) */                                                          \
  /*_(mm_cmpistro) */                                                          \
  /*_(mm_cmpistrs) */                                                          \
  /*_(mm_cmpistrz) */                                                          \
  _(mm_crc32_u16)                                                              \
  _(mm_crc32_u32)                                                              \
  _(mm_crc32_u64)                                                              \
  _(mm_crc32_u8)                                                               \
  /* AES */                                                                    \
  _(mm_aesenc_si128)                                                           \
  _(mm_aesdec_si128)                                                           \
  _(mm_aesenclast_si128)                                                       \
  _(mm_aesdeclast_si128)                                                       \
  _(mm_aesimc_si128)                                                           \
  _(mm_aeskeygenassist_si128)                                                  \
  /* Others */                                                                 \
  _(mm_clmulepi64_si128)                                                       \
  _(mm_get_denormals_zero_mode)                                                \
  _(mm_popcnt_u32)                                                             \
  _(mm_popcnt_u64)                                                             \
  _(mm_set_denormals_zero_mode)                                                \
  _(rdtsc)                                                                     \
  _(last) /* This indicates the end of macros */

namespace SSE2RVV {
// The way unit tests are implemented is that 10,000 random floating point and
// integer vec4 numbers are generated as sample data.
//
// A short C implementation of every intrinsic is implemented and compared to
// the actual expected results from the corresponding SSE intrinsic against all
// of the 10,000 randomized input vectors. When running on RISCV, then the
// results are compared to the RISCV approximate version.
extern const char *instruction_string[];
enum INSTRUCTION_TEST {
#define _(x) it_##x,
  INTRIN_LIST
#undef _
};

class SSE2RVV_TEST {
public:
  static SSE2RVV_TEST *create(void); // create the test.

  // Run test of this instruction;
  // Passed: TEST_SUCCESS (1)
  // Failed: TEST_FAIL (0)
  // Unimplemented: TEST_UNIMPL (-1)
  virtual result_t run_test(INSTRUCTION_TEST test) = 0;
  virtual void release(void) = 0;
};

} // namespace SSE2RVV

#endif // SSE2RVV_TEST_H
