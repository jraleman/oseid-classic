gcc -O2 -s -m32 -pedantic -Wall ./source/oseidc.c -o ./release/win32/oseidc.exe
wcl -cc -0 -bcl=dos -wx -ox ./source/oseidc.c -fe=./release/dos_8086/oseidc.exe
cd ./tools/upx/
upxWin32 --best ../../release/win32/oseidc.exe -o../../release/win32_upx/oseidc.exe
upxwin32 --best --8086 ../../release/dos_8086/oseidc.exe -o../../release/dos_8086_upx/oseidc.exe
cd ../..