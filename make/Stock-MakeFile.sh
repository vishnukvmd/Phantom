#!/bin/sh

echo "-------------------------------------------------"
echo "--- Phantom Kernel Packing ---"
echo "-------------------------------------------------"
echo "1) Copying zImage..."
cp ../kernel/arch/arm/boot/zImage ./tmp/zImage
echo "2) Copying WiFi Modules to Ramdisk..."
cp ../kernel/net/compat-wireless/drivers/staging/cw1200/cw1200_core.ko ../ramdisk-$1/lib/modules/
cp ../kernel/net/compat-wireless/drivers/staging/cw1200/cw1200_wlan.ko ../ramdisk-$1/lib/modules/
echo "3) Packing Ramdisk..."
./mkbootfs ../ramdisk-$1 | gzip > ./tmp/ramdisk.img
echo "4) Creating Kernel.elf..."
rm kernel.elf
python mkelf.py -o ./kernel.elf ./tmp/zImage@0x00008000 ./tmp/ramdisk.img@0x1000000,ramdisk cmdline.txt@cmdline
echo "5) Creating CWM Flashable zip..."
rm ./tmp/cwm.zip
zip -r ./tmp/cwm.zip ./kernel.elf ./META-INF
echo "6) Signing the zip file..."
#rm ./output/Phantom-Stock.zip
java -classpath testsign.jar testsign ./tmp/cwm.zip ./output/Phantom-Stock-$1-$2.zip
echo "7) Removing temporary files..."
#rm ./kernel.elf
echo "-------------------------------------------------"
echo "                     All Done! :)"
echo "-------------------------------------------------"
