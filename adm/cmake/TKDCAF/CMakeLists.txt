SET(TOOLKIT TKDCAF)

SET(TOOLKIT_MODULES
	DDF
	DDocStd
	DNaming
	DDataStd
	DPrsStd
	DrawDim
)
SET(TOOLKIT_DEPENDS TKCAF
	TKernel
	TKBool
	TKLCAF
	TKCAF
	TKViewerTest
	TKBO
	TKG3d
	TKTopAlgo
	TKGeomBase
	TKV3d
	TKService
	TKMath
	TKCDF
	TKBRep
	TKGeomAlgo
	TKFillet
	TKG2d
	TKDraw
	TKPrim
	TKNIS
	TKV2d
)

SET(TOOLKIT_IS_PRIVATE TRUE)

INCLUDE(../BuildToolkit.cmake)

