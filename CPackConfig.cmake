include(InstallRequiredSystemLibraries)

set(CPACK_PACKAGE_NAME "rk2-observer")
set(CPACK_PACKAGE_VERSION "1.0.0")
set(CPACK_PACKAGE_CONTACT "tananaa")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "Observer pattern implementation")
set(CPACK_DEBIAN_PACKAGE_NAME "rk2-observer")
set(CPACK_DEBIAN_PACKAGE_ARCHITECTURE "amd64")

include(CPack)
