#pragma once
void KhoiTaoDanhSachDocGia(int& n, char Code[20][20], char Name[20][20], unsigned int CCCD[20], int bDay[20], int bMonth[20], int bYear[20], char Gender[20][20], char Email[20][20], char Addr[20][20], int issueDay[20], int issueMonth[20], int issueYear[20], int dueDay[20], int dueMonth[20], int dueYear[20]);
void XemDanhSachDocGia(int n, char Code[20][20], char Name[20][20], unsigned int CCCD[20], int bDay[20], int bMonth[20], int bYear[20], char Gender[20][20], char Email[20][20], char Addr[20][20], int issueDay[20], int issueMonth[20], int issueYear[20], int dueDay[20], int dueMonth[20], int dueYear[20]);

void ThemDocGia(int& n, char Code[20][20], char Name[20][20], unsigned int CCCD[20], int bDay[20], int bMonth[20], int bYear[20], char Gender[20][20], char Email[20][20], char Addr[20][20], int issueDay[20], int issueMonth[20], int issueYear[20], int dueDay[20], int dueMonth[20], int dueYear[20]);
void ChinhSuaThongTinDocGia(int& nReaders, char Code[20][20], char Name[20][20], unsigned int CCCD[20], int bDay[20], int bMonth[20], int bYear[20], char Gender[20][20], char Email[20][20], char Addr[20][20], int issueDay[20], int issueMonth[20], int issueYear[20], int dueDay[20], int dueMonth[20], int dueYear[20]);
void ChinhSuaMaDocGia(char Code[20][20], int Vitri, int nReaders);
void ChinhSuaTenDocGia(char Name[20][20], int Vitri, int nReaders);
void ChinhSuaCCCD(unsigned int CCCD[20], int Vitri, int nReaders);
void ChinhSuaBirthday(int bDay[20], int bMonth[20], int bYear[20], int Vitri, int nReaders);
void ChinhSuaGioiTinh(char Gender[20][20], int Vitri, int nReaders);
void ChinhSuaEmail(char Email[20][20], int Vitri, int nReaders);
void ChinhSuaAddr(char Addr[20][20], int Vitri, int nReaders);
void ChinhIssueDay(int issueDay[20], int issueMonth[20], int issueYear[20], int dueDay[20], int dueMonth[20], int dueYear[20], int Vitri, int nReaders);
void XoaThongTinDocGia(int& nReaders, char Code[20][20], char Name[20][20], unsigned int CCCD[20], int bDay[20], int bMonth[20], int bYear[20], char Gender[20][20], char Email[20][20], char Addr[20][20], int issueDay[20], int issueMonth[20], int issueYear[20], int dueDay[20], int dueMonth[20], int dueYear[20]);

int TimVitriCCCD(unsigned int CCCD[20], int nReaders, unsigned int n);
int TimVitriMaDocGia(int nReaders, char Code[20][20], char Code_looking[20]);

void TimDocGiaTheoTen(int& nReaders, char Code[20][20], char Name[20][20], unsigned int CCCD[20], int bDay[20], int bMonth[20], int bYear[20], char Gender[20][20], char Email[20][20], char Addr[20][20], int issueDay[20], int issueMonth[20], int issueYear[20], int dueDay[20], int dueMonth[20], int dueYear[20]);
void TimDocGiaTheoCCCD(int& nReaders, char Code[20][20], char Name[20][20], unsigned int CCCD[20], int bDay[20], int bMonth[20], int bYear[20], char Gender[20][20], char Email[20][20], char Addr[20][20], int issueDay[20], int issueMonth[20], int issueYear[20], int dueDay[20], int dueMonth[20], int dueYear[20]);

bool KiemTraCCCDTrung(unsigned int CCCD[20], int nReaders, int Vitri);
bool KiemTraCodeTrung(char Code[20][20], int nReaders, int Vitri);
bool KiemTraTonTaiCode(char Code[20][20], int nReaders, char Code_looking[20]);

int DemSoDocGiaTheoTen(int nReaders, char Name[20][20], char Name_looking[20]);
void XemDanhSachDocGiaTheoTen(int nReaders, int n, char Code[20][20], char Name[20][20], char Name_looking[20], unsigned int CCCD[20], int bDay[20], int bMonth[20], int bYear[20], char Gender[20][20], char Email[20][20], char Addr[20][20], int issueDay[20], int issueMonth[20], int issueYear[20], int dueDay[20], int dueMonth[20], int dueYear[20]);
