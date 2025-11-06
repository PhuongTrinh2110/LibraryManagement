#include "ThuVienHam.h"
//Menu chính chọn chức năng
void MainMenu(int& n)
{
	printf("QUAN LY THU VIEN TRUONG DAI HOC KHOA HOC TU NHIEN - DHQG TPHCM\n");
	printf("----------------------------MAIN MENU-------------------------\n");
	printf("1. Xem danh sach doc gia trong thu vien\n");
	printf("2. Chinh sua danh sach doc gia\n");
	printf("3. Xem danh sach cac sach hien co trong thu vien\n");
	printf("4. Chinh sua danh sach cac sach\n");
	printf("5. Muon/ tra sach\n");
	printf("6. Thong ke so luong\n");
	printf("7. Tim doc gia/ sach\n");
	printf("0. Thoat chuong trinh\n");
	printf("\n-------------------------------------------------------------\n");
	printf("CHON CHUC NANG CAN THUC HIEN: ");
	scanf_s("%d", &n);
	printf("\n-------------------------------------------------------------\n");
}
//Menu chỉnh sửa danh sách độc giả: Thêm/ Sửa/ Xóa độc giả
void MenuChinhSuaListDocGia(int& n)
{
	printf("QUAN LY THU VIEN TRUONG DAI HOC KHOA HOC TU NHIEN - DHQG TPHCM\n");
	printf("-------------------CHINH SUA DANH SACH DOC GIA----------------\n");
	printf("1. Them doc gia\n");
	printf("2. Chinh sua thong tin doc gia\n");
	printf("3. Xoa thong tin doc gia\n");
	printf("\n-------------------------------------------------------------\n");
	printf("CHON CHUC NANG CAN THUC HIEN: ");
	scanf_s("%d", &n);
	printf("\n-------------------------------------------------------------\n");
}
//Menu chỉnh sửa thông tin danh sách các sách trong thư viện: Thêm/ Sửa/ Xóa sách
void MenuChinhSuaListSach(int& n)
{
	printf("QUAN LY THU VIEN TRUONG DAI HOC KHOA HOC TU NHIEN - DHQG TPHCM\n");
	printf("----------------CHINH SUA DANH DANH SACH CAC SACH-------------\n");
	printf("1. Them sach moi\n");
	printf("2. Chinh sua thong tin sach\n");
	printf("3. Xoa thong tin sach\n");
	printf("\n-------------------------------------------------------------\n");
	printf("CHON CHUC NANG CAN THUC HIEN: ");
	scanf_s("%d", &n);
	printf("\n-------------------------------------------------------------\n");
}
//Menu lập phiếu mượn sách hoặc trả sách
void MenuMuonTraSach(int& n)
{
	printf("QUAN LY THU VIEN TRUONG DAI HOC KHOA HOC TU NHIEN - DHQG TPHCM\n");
	printf("------------------------MUON / TRA SACH-----------------------\n");
	printf("1. Lap phieu muon sach\n");
	printf("2. Lap phieu tra sach\n");
	printf("3. Xem danh sach muon sach\n");
	printf("4. Xem lich su tra sach\n");
	printf("5. Bao mat sach\n");
	printf("\n-------------------------------------------------------------\n");
	printf("CHON CHUC NANG CAN THUC HIEN: ");
	scanf_s("%d", &n);
	printf("\n-------------------------------------------------------------\n");
}
//Menu thống kê số lượng sách/ độc giả
void MenuThongKeSoLuong(int& n)
{
	printf("QUAN LY THU VIEN TRUONG DAI HOC KHOA HOC TU NHIEN - DHQG TPHCM\n");
	printf("-----------------------THONG KE SO LUONG----------------------\n");
	printf("1. Thong ke so luong sach trong thu vien\n");
	printf("2. Thong ke so luong sach theo the loai\n");
	printf("3. Thong ke so luong doc gia\n");
	printf("4. Thong ke so luong doc gia theo gioi tinh\n");
	printf("5. Thong ke so sach dang duoc muon\n");
	printf("6. Thong ke danh sach doc gia bi tre han\n");
	printf("\n-------------------------------------------------------------\n");
	printf("CHON CHUC NANG CAN THUC HIEN: ");
	scanf_s("%d", &n);
	printf("\n-------------------------------------------------------------\n");
}
//Menu tìm kiếm độc giả/ sách
void MenuSearch(int& n)
{
	printf("QUAN LY THU VIEN TRUONG DAI HOC KHOA HOC TU NHIEN - DHQG TPHCM\n");
	printf("-------------TIM KIEM THONG TIN DOC GIA / SACH----------------\n");
	printf("1. Tim kiem doc gia theo CCCD\n");
	printf("2. Tim kiem doc gia theo Ten\n");
	printf("3. Tim sach theo ISBN\n");
	printf("4. Tim sach theo ten sach\n");
	printf("\n-------------------------------------------------------------\n");
	printf("CHON CHUC NANG CAN THUC HIEN: ");
	scanf_s("%d", &n);
	printf("\n-------------------------------------------------------------\n");
}
