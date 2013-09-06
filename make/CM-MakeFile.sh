#!/bin/sh

echo "-------------------------------------------------"
echo "--- Phantom Kernel Packing ---"
echo "-------------------------------------------------"
echo "1) Copying zImage..."
cp ../kernel/arch/arm/boot/zImage ./tmp/zImage
echo "2) Packing Ramdisk..."
./mkbootfs ../ramdisk-$1-CM10 | gzip > ./tmp/ramdisk.img
echo "3) Creating Kernel.elf..."
python mkelf.py -o ./kernel.elf ./tmp/zImage@0x00008000 ./tmp/ramdisk.img@0x1000000,ramdisk cmdline.txt@cmdline
echo "4) Creating CWM Flashable zip..."
rm ./tmp/cwm.zip
zip -r ./tmp/cwm.zip ./kernel.elf ./META-INF
echo "5) Signing the zip file..."
rm ./output/Phantom-CM.zip
java -classpath testsign.jar testsign ./tmp/cwm.zip ./output/Phantom-CM10.1-$1-$2.zip
echo "6) Removing temporary files..."
rm ./kernel.elf
echo "-------------------------------------------------"
echo "                     All Done! :)"
echo "-------------------------------------------------"
