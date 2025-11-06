#pragma once
void KhoiTaoListSach(int& nBooks, char ISBN[20][20], char BookName[20][20], char Author[20][20], char NXB[20][20], int PublishYear[20], char Type[20][20], unsigned int Price[20], int QTy[20], int allQTy[20]);
void XemListSach(int nBooks, char ISBN[20][20], char BookName[20][20], char Author[20][20], char NXB[20][20], int PublishYear[20], char Type[20][20], unsigned int Price[20], int QTy[20]);

void ThemSach(int& nBooks, char ISBN[20][20], char BookName[20][20], char Author[20][20], char NXB[20][20], int PublishYear[20],char Type[20][20], unsigned int Price[20], int QTy[20], int allQTy[20]);
void ChinhSuaThongTinSach(int nBooks, char ISBN[20][20], char BookName[20][20], char Author[20][20], char NXB[20][20], int PublishYear[20], char Type[20][20], unsigned int Price[20], int QTy[20], int allQTy[20]);
void ChinhSuaISBN(int nBooks, char ISBN[20][20], int Vitri);
void ChinhSuaTenSach(int nBooks, char BookName[20][20], int Vitri);
void ChinhSuaTacGia(int nBooks, char Author[20][20], int Vitri);
void ChinhSuaNXB(int nBooks, char NXB[20][20], int Vitri);
void ChinhSuaPublishYear(int nBooks, int PublishYear[20], int Vitri);
void ChinhSuaTheLoai(int nBooks, char Type[20][20], int Vitri);
void ChinhSuaGia(int nBooks, unsigned int Price[20], int Vitri);
void ChinhSuaSoLuong(int nBooks, int QTy[20], int allQTy[20], int Vitri);
void XoaThongTinSach(int& nBooks, char ISBN[20][20], char BookName[20][20], char Author[20][20], char NXB[20][20], int PublishYear[20], char Type[20][20], unsigned int Price[20], int QTy[20], int allQTy[20]);

int TimVitriISBN(char ISBN[20][20], char ISBN_looking[20], int nBooks);

void TimSachTheoISBN(int nBooks, char ISBN[20][20], char BookName[20][20], char Author[20][20], char NXB[20][20], int PublishYear[20], char Type[20][20], unsigned int Price[20], int QTy[20]);
void TimSachTheoTen(int nBooks, char ISBN[20][20], char BookName[20][20], char Author[20][20], char NXB[20][20], int PublishYear[20], char Type[20][20], unsigned int Price[20], int QTy[20]);

bool KiemTraISBN(int nBooks, char ISBN[20][20], int Vitri);
bool KiemTraTonTaiISBN(int nBooks, char ISBN[20][20], char ISBN_looking[20]);

int DemSoLuongTheoTenSach(int nBooks, char BookName[20][20], char BookName_looking[20]);
void XemDanhSachTheoTenSach(int nBooks, int n, char ISBN[20][20], char BookName[20][20], char BookName_looking[20], char Author[20][20], char NXB[20][20], int PublishYear[20], char Type[20][20], unsigned int Price[20], int QTy[20]);
