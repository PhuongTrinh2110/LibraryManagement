#pragma once
void ThongKeSoLuongSachTong(int nBooks, char ISBN[20][20], char BookName[20][20], char Author[20][20], char NXB[20][20], int PublishYear[20], char Type[20][20], unsigned int Price[20], int allQTy[20]);
void ThongKeSLTheoTheLoai(int nBooks, char Type[20][20], int allQTy[20]);
void ThongKeSLDGtheoGioiTinh(int nReaders, char Gender[20][20]);
void ThongKeDocGiaTreHan(int nBorrow, char bCode[20][20], char bISBN[20][20], int borrowDay[20], int borrowMonth[20], int borrowYear[20], int returnDueDay[20], int returnDueMonth[20], int returnDueYear[20], int currentDay, int currentMonth, int CurrentYear);

