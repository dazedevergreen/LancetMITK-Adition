set(SRC_CPP_FILES

)

set(INTERNAL_CPP_FILES
  org_mitk_lancet_InstantiationCamera_Activator.cpp
  InstantiationCamera.cpp
  CameraConnectionTab.cpp
  CameraTransTab.cpp
  CameraRectLabel.cpp
  VideoWidget.cpp
  VideoLabel.cpp
)

set(UI_FILES
  src/internal/InstantiationCameraControls.ui
)

set(MOC_H_FILES
  src/internal/org_mitk_lancet_InstantiationCamera_Activator.h
  src/internal/InstantiationCamera.h
  src/internal/CameraConnectionTab.h
  src/internal/CameraTransTab.h
  src/internal/CameraRectLabel.h
  src/internal/VideoWidget.h
  src/internal/VideoLabel.h
)

# list of resource files which can be used by the plug-in
# system without loading the plug-ins shared library,
# for example the icon used in the menu and tabs for the
# plug-in views in the workbench
set(CACHED_RESOURCE_FILES
  resources/icon.xpm
  plugin.xml
)

# list of Qt .qrc files which contain additional resources
# specific to this plugin
set(QRC_FILES

)

set(CPP_FILES )

foreach(file ${SRC_CPP_FILES})
  set(CPP_FILES ${CPP_FILES} src/${file})
endforeach(file ${SRC_CPP_FILES})

foreach(file ${INTERNAL_CPP_FILES})
  set(CPP_FILES ${CPP_FILES} src/internal/${file})
endforeach(file ${INTERNAL_CPP_FILES})
