SET(TOOLKIT FWOSPlugin)

SET(TOOLKIT_MODULES
	FWOSDriver
)
SET(TOOLKIT_DEPENDS
	TKCDF
	TKernel
)

INCLUDE(../BuildToolkit.cmake)

