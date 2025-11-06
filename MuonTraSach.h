#pragma once
void KhoiTaoDanhSachMuonSach(int& nBorrow, char bCode[20][20], char bISBN[20][20], int borrowDay[20], int borrowMonth[20], int borrowYear[20], int returnDueDay[20], int returnDueMonth[20], int returnDueYear[20]);
void KhoiTaoLichSuTraSach(int& nReturn, char rCode[20][20], char rISBN[20][20], int rborrowDay[20], int rborrowMonth[20], int rborrowYear[20], int rreturnDueDay[20], int rreturnDueMonth[20], int rreturnDueYear[20], int returnActDay[20], int returnActMonth[20], int returnActYear[20], int DelayDay[20], unsigned int TotalFine[20]);

void XemDanhSachMuonSach(int nBorrow, char bCode[20][20], char bISBN[20][20], int borrowDay[20], int borrowMonth[20], int borrowYear[20], int returnDueDay[20], int returnDueMonth[20], int returnDueYear[20]);
void XemLichSuTraSach(int nReturn, char rCode[20][20], char rISBN[20][20], int rborrowDay[20], int rborrowMonth[20], int rborrowYear[20], int rreturnDueDay[20], int rreturnDueMonth[20], int rreturnDueYear[20], int returnActDay[20], int returnActMonth[20], int returnActYear[20], int DelayDay[20], unsigned int TotalFine[20]);

void LapPhieuMuonSach(int& nBorrow, int nReaders, int nBooks, char bCode[20][20], char Code[20][20], char bISBN[20][20], char ISBN[20][20], int borrowDay[20], int borrowMonth[20], int borrowYear[20], int returnDueDay[20], int returnDueMonth[20], int returnDueYear[20], int Qty[20]);
void LapPhieuTraSach(int& nBorrow, int& nReturn, int nBooks, char bCode[20][20], char rCode[20][20], char bISBN[20][20], char rISBN[20][20], char ISBN[20][20], int borrowDay[20], int borrowMonth[20], int borrowYear[20], int returnDueDay[20], int returnDueMonth[20], int returnDueYear[20], int rborrowDay[20], int rborrowMonth[20], int rborrowYear[20], int rreturnDueDay[20], int rreturnDueMonth[20], int rreturnDueYear[20], int returnActDay[20], int returnActMonth[20], int returnActYear[20], int QTy[20], int DelayDay[20], unsigned int TotalFine[20]);
void BaoMatSach(int& nBorrow, int& nReturn, int nBooks, char bCode[20][20], char rCode[20][20], char bISBN[20][20], char rISBN[20][20], char ISBN[20][20], int borrowDay[20], int borrowMonth[20], int borrowYear[20], int returnDueDay[20], int returnDueMonth[20], int returnDueYear[20], int rborrowDay[20], int rborrowMonth[20], int rborrowYear[20], int rreturnDueDay[20], int rreturnDueMonth[20], int rreturnDueYear[20], int returnActDay[20], int returnActMonth[20], int returnActYear[20], int QTy[20], int DelayDay[20], unsigned int TotalFine[20], unsigned int Price[20], int allQTy[20]);

bool DocGiaCoMuonSach(int nBorrow, char bCode[20][20], char bISBN[20][20], char Code_looking[20], char ISBN_looking[20]);
int VitriDocGiavaISBN(int nBorrow, char bCode[20][20], char bISBN[20][20], char Code_looking[20], char ISBN_looking[20]);

