#!/bin/bash
set -e

echo "=== Сборка проекта ==="
rm -rf _build
cmake -H. -B_build -DCMAKE_INSTALL_PREFIX=_install
cmake --build _build

echo "=== Сборка с тестами ==="
rm -rf _build_tests
cmake -H. -B_build_tests -DBUILD_TESTS=ON
cmake --build _build_tests

echo "=== Запуск тестов ==="
./_build_tests/tests

echo "=== Установка ==="
cmake --build _build --target install

echo "=== Создание DEB пакета ==="
cd _build
cpack -G DEB
cd ..

echo "=== Готово ==="
ls -la _build/*.deb
