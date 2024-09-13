#We need to source the include files, so that QT's MOC can see them.
target_sources(app2D-Sandbox PRIVATE
    ${INCLUDE_FILES}
)