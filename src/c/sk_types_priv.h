/*
 * Copyright 2014 Google Inc.
 * Copyright 2015 Xamarin Inc.
 * Copyright 2017 Microsoft Corporation. All rights reserved.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef sk_types_priv_DEFINED
#define sk_types_priv_DEFINED

#include "sk_types.h"


// Define a mapping between a C++ type and the C type.
//
// Usual Values:
//  - C++  |  SkType   |  SkSomeType
//  - C    |  sk_type  |  sk_some_type_t
//  - Map  |  Name     |  ToSomeType / AsSomeType
//
#define DEF_MAP_DECL(SkType, sk_type, Name, Declaration)       \
    Declaration;                                               \
    static inline const SkType& As##Name(const sk_type& t) {   \
        return reinterpret_cast<const SkType&>(t);             \
    }                                                          \
    static inline const SkType* As##Name(const sk_type* t) {   \
        return reinterpret_cast<const SkType*>(t);             \
    }                                                          \
    static inline SkType& As##Name(sk_type& t) {               \
        return reinterpret_cast<SkType&>(t);                   \
    }                                                          \
    static inline SkType* As##Name(sk_type* t) {               \
        return reinterpret_cast<SkType*>(t);                   \
    }                                                          \
    static inline const sk_type& To##Name(const SkType& t) {   \
        return reinterpret_cast<const sk_type&>(t);            \
    }                                                          \
    static inline const sk_type* To##Name(const SkType* t) {   \
        return reinterpret_cast<const sk_type*>(t);            \
    }                                                          \
    static inline sk_type& To##Name(SkType& t) {               \
        return reinterpret_cast<sk_type&>(t);                  \
    }                                                          \
    static inline sk_type* To##Name(SkType* t) {               \
        return reinterpret_cast<sk_type*>(t);                  \
    }

#define DEF_CLASS_MAP(SkType, sk_type, Name)                   \
    DEF_MAP_DECL(SkType, sk_type, Name, class SkType)

#define DEF_STRUCT_MAP(SkType, sk_type, Name)                  \
    DEF_MAP_DECL(SkType, sk_type, Name, struct SkType)

#define DEF_MAP(SkType, sk_type, Name)                         \
    DEF_MAP_DECL(SkType, sk_type, Name, )


DEF_CLASS_MAP(Sk3DView, sk_3dview_t, 3DView)
DEF_CLASS_MAP(SkBitmap, sk_bitmap_t, Bitmap)
DEF_CLASS_MAP(SkCanvas, sk_canvas_t, Canvas)
DEF_CLASS_MAP(SkCodec, sk_codec_t, Codec)
DEF_CLASS_MAP(SkColorFilter, sk_colorfilter_t, ColorFilter)
DEF_CLASS_MAP(SkColorSpace, sk_colorspace_t, ColorSpace)
DEF_CLASS_MAP(SkColorTable, sk_colortable_t, ColorTable)
DEF_CLASS_MAP(SkData, sk_data_t, Data)
DEF_CLASS_MAP(SkDocument, sk_document_t, Document)
DEF_CLASS_MAP(SkDrawable, sk_drawable_t, Drawable)
DEF_CLASS_MAP(SkDynamicMemoryWStream, sk_wstream_dynamicmemorystream_t, DynamicMemoryWStream)
DEF_CLASS_MAP(SkFILEStream, sk_stream_filestream_t, FileStream)
DEF_CLASS_MAP(SkFILEWStream, sk_wstream_filestream_t, FileWStream)
DEF_CLASS_MAP(SkFontMgr, sk_fontmgr_t, FontMgr)
DEF_CLASS_MAP(SkFontStyle, sk_fontstyle_t, FontStyle)
DEF_CLASS_MAP(SkFontStyleSet, sk_fontstyleset_t, FontStyleSet)
DEF_CLASS_MAP(SkImage, sk_image_t, Image)
DEF_CLASS_MAP(SkImageFilter, sk_imagefilter_t, ImageFilter)
DEF_CLASS_MAP(SkMaskFilter, sk_maskfilter_t, MaskFilter)
DEF_CLASS_MAP(SkMatrix44, sk_matrix44_t, Matrix44)
DEF_CLASS_MAP(SkMemoryStream, sk_stream_memorystream_t, MemoryStream)
DEF_CLASS_MAP(SkNWayCanvas, sk_nway_canvas_t, NWayCanvas)
DEF_CLASS_MAP(SkNoDrawCanvas, sk_nodraw_canvas_t, NoDrawCanvas)
DEF_CLASS_MAP(SkOverdrawCanvas, sk_overdraw_canvas_t, OverdrawCanvas)
DEF_CLASS_MAP(SkOpBuilder, sk_opbuilder_t, OpBuilder)
DEF_CLASS_MAP(SkPaint, sk_paint_t, Paint)
DEF_CLASS_MAP(SkPath, sk_path_t, Path)
DEF_CLASS_MAP(SkPathEffect, sk_path_effect_t, PathEffect)
DEF_CLASS_MAP(SkPathMeasure, sk_pathmeasure_t, PathMeasure)
DEF_CLASS_MAP(SkPicture, sk_picture_t, Picture)
DEF_CLASS_MAP(SkPictureRecorder, sk_picture_recorder_t, PictureRecorder)
DEF_CLASS_MAP(SkPixmap, sk_pixmap_t, Pixmap)
DEF_CLASS_MAP(SkRegion, sk_region_t, Region)
DEF_CLASS_MAP(SkRRect, sk_rrect_t, RRect)
DEF_CLASS_MAP(SkShader, sk_shader_t, Shader)
DEF_CLASS_MAP(SkStream, sk_stream_t, Stream)
DEF_CLASS_MAP(SkStreamAsset, sk_stream_asset_t, StreamAsset)
DEF_CLASS_MAP(SkStreamRewindable, sk_stream_streamrewindable_t, StreamRewindable)
DEF_CLASS_MAP(SkString, sk_string_t, String)
DEF_CLASS_MAP(SkSurface, sk_surface_t, Surface)
DEF_CLASS_MAP(SkSurfaceProps, sk_surfaceprops_t, SurfaceProps)
DEF_CLASS_MAP(SkTextBlob, sk_textblob_t, TextBlob)
DEF_CLASS_MAP(SkTextBlobBuilder, sk_textblob_builder_t, TextBlobBuilder)
DEF_CLASS_MAP(SkTypeface, sk_typeface_t, Typeface)
DEF_CLASS_MAP(SkVertices, sk_vertices_t, Vertices)
DEF_CLASS_MAP(SkWStream, sk_wstream_t, WStream)
DEF_CLASS_MAP(SkXMLStreamWriter, sk_xmlstreamwriter_t, XMLStreamWriter)
DEF_CLASS_MAP(SkXMLWriter, sk_xmlwriter_t, XMLWriter)

DEF_CLASS_MAP(GrContext, gr_context_t, GrContext)
DEF_CLASS_MAP(GrBackendTexture, gr_backendtexture_t, GrBackendTexture)
DEF_CLASS_MAP(GrBackendRenderTarget, gr_backendrendertarget_t, GrBackendRenderTarget)

DEF_STRUCT_MAP(SkColorSpacePrimaries, sk_colorspaceprimaries_t, ColorSpacePrimaries)
DEF_STRUCT_MAP(SkColorSpaceTransferFn, sk_colorspace_transfer_fn_t, ColorSpaceTransferFn)
DEF_STRUCT_MAP(SkHighContrastConfig, sk_highcontrastconfig_t, HighContrastConfig)
DEF_STRUCT_MAP(SkIPoint, sk_ipoint_t, IPoint)
DEF_STRUCT_MAP(SkIRect, sk_irect_t, IRect)
DEF_STRUCT_MAP(SkISize, sk_isize_t, ISize)
DEF_STRUCT_MAP(SkMask, sk_mask_t, Mask)
DEF_STRUCT_MAP(SkPoint, sk_point_t, Point)
DEF_STRUCT_MAP(SkPoint3, sk_point3_t, Point3)
DEF_STRUCT_MAP(SkRect, sk_rect_t, Rect)
DEF_STRUCT_MAP(SkSize, sk_size_t, Size)

DEF_STRUCT_MAP(GrGLTextureInfo, gr_gl_textureinfo_t, GrGLTextureInfo)
DEF_STRUCT_MAP(GrGLFramebufferInfo, gr_gl_framebufferinfo_t, GrGLFramebufferInfo)
DEF_STRUCT_MAP(GrGLInterface, gr_glinterface_t, GrGLInterface)

#include "SkCanvas.h"
DEF_MAP(SkCanvas::Lattice, sk_lattice_t, Lattice)

#include "SkCodec.h"
DEF_MAP(SkCodec::FrameInfo, sk_codec_frameinfo_t, FrameInfo)
DEF_MAP(SkCodec::Options, sk_codec_options_t, CodecOptions)

#include "SkImageFilter.h"
DEF_MAP(SkImageFilter::CropRect, sk_imagefilter_croprect_t, ImageFilterCropRect)

#include "SkJpegEncoder.h"
DEF_MAP(SkJpegEncoder::Options, sk_jpegencoder_options_t, JpegEncoderOptions)

#include "SkPaint.h"
DEF_MAP(SkPaint::FontMetrics, sk_fontmetrics_t, FontMetrics)

#include "SkPath.h"
DEF_MAP(SkPath::Iter, sk_path_iterator_t, PathIter)
DEF_MAP(SkPath::RawIter, sk_path_rawiterator_t, PathRawIter)

#include "SkPngEncoder.h"
DEF_MAP(SkPngEncoder::Options, sk_pngencoder_options_t, PngEncoderOptions)

#include "SkTime.h"
DEF_MAP(SkTime::DateTime, sk_time_datetime_t, TimeDateTime)

#include "SkWebpEncoder.h"
DEF_MAP(SkWebpEncoder::Options, sk_webpencoder_options_t, WebpEncoderOptions)

#include "SkMatrix.h"
static inline SkMatrix AsMatrix(const sk_matrix_t* matrix) {
    return SkMatrix::MakeAll(
        matrix->scaleX, matrix->skewX,  matrix->transX,
        matrix->skewY,  matrix->scaleY, matrix->transY,
        matrix->persp0, matrix->persp1, matrix->persp2);
}
static inline sk_matrix_t ToMatrix(const SkMatrix* matrix) {
    sk_matrix_t m;
    m.scaleX = matrix->get(SkMatrix::kMScaleX);
    m.skewX  = matrix->get(SkMatrix::kMSkewX);
    m.transX = matrix->get(SkMatrix::kMTransX);
    m.skewY  = matrix->get(SkMatrix::kMSkewY);
    m.scaleY = matrix->get(SkMatrix::kMScaleY);
    m.transY = matrix->get(SkMatrix::kMTransY);
    m.persp0 = matrix->get(SkMatrix::kMPersp0);
    m.persp1 = matrix->get(SkMatrix::kMPersp1);
    m.persp2 = matrix->get(SkMatrix::kMPersp2);
    return m;
}

#include "SkImageInfo.h"
static inline SkImageInfo AsImageInfo(const sk_imageinfo_t* info) {
    return SkImageInfo::Make(
        info->width,
        info->height,
        (SkColorType)info->colorType,
        (SkAlphaType)info->alphaType,
        sk_ref_sp(AsColorSpace(info->colorspace))); 
}
static inline sk_imageinfo_t ToImageInfo(const SkImageInfo info) {
    return {
        ToColorSpace(info.refColorSpace().release()),
        info.width(),
        info.height(),
        (sk_colortype_t)info.colorType(),
        (sk_alphatype_t)info.alphaType(),
    };
}

#include "SkTextBlob.h"
static inline SkTextBlobBuilder::RunBuffer AsTextBlobBuilderRunBuffer(const sk_textblob_builder_runbuffer_t* runbuffer) {
    return {
        (SkGlyphID*)runbuffer->glyphs,
        (SkScalar*)runbuffer->pos,
        (char*)runbuffer->utf8text,
        (uint32_t*)runbuffer->clusters,
    };
}
static inline sk_textblob_builder_runbuffer_t ToTextBlobBuilderRunBuffer(const SkTextBlobBuilder::RunBuffer runbuffer) {
    return {
        runbuffer.glyphs,
        runbuffer.pos,
        runbuffer.utf8text,
        runbuffer.clusters,
    };
}

#include "SkDocument.h"
static inline SkDocument::OptionalTimestamp AsDocumentOptionalTimestamp(const sk_time_datetime_t* datetime) {
    SkDocument::OptionalTimestamp ts;
    if (datetime) {
        ts.fEnabled = true;
        ts.fDateTime = *AsTimeDateTime(datetime);
    }
    return ts;
}
static inline SkString AsDocumentOptionalString(const sk_string_t* skstring) {
    if (skstring) {
        return *AsString(skstring);
    } else {
        return SkString();
    }
}
static inline SkDocument::PDFMetadata AsDocumentPDFMetadata(const sk_document_pdf_metadata_t* metadata) {
    SkDocument::PDFMetadata md;
    md.fTitle = AsDocumentOptionalString(metadata->fTitle);
    md.fAuthor = AsDocumentOptionalString(metadata->fAuthor);
    md.fSubject = AsDocumentOptionalString(metadata->fSubject);
    md.fKeywords = AsDocumentOptionalString(metadata->fKeywords);
    md.fCreator = AsDocumentOptionalString(metadata->fCreator);
    md.fProducer = AsDocumentOptionalString(metadata->fProducer);
    md.fCreation =  AsDocumentOptionalTimestamp(metadata->fCreation),
    md.fModified =  AsDocumentOptionalTimestamp(metadata->fModified),
    md.fRasterDPI = metadata->fRasterDPI;
    md.fPDFA = metadata->fPDFA;
    md.fEncodingQuality = metadata->fEncodingQuality;
    return md;
}

#endif
