#include <iostream>
#include <string>
using namespace std;

struct Sach {
    int ma;
    string ten;
    string tacGia;
    string theLoai;
    int tinhTrang;
    string khachHang;
    Sach* tiep;
};

Sach* taoSach(int ma, string ten, string tacGia, string theLoai, int tinhTrang, string khachHang) {
    Sach* sachMoi = new Sach;
    sachMoi->ma = ma;
    sachMoi->ten = ten;
    sachMoi->tacGia = tacGia;
    sachMoi->theLoai = theLoai;
    sachMoi->tinhTrang = tinhTrang;
    sachMoi->khachHang = khachHang;
    sachMoi->tiep = nullptr;
    return sachMoi;
}

Sach* khoiTaoCuaHangSach() {
    Sach* dau = taoSach(1, "Sach1", "TacGia1", "Khoa hoc", 0, "");
    Sach* hienTai = dau;
    
    // Khởi tạo DSLK với 100 đầu sách
    for (int i = 2; i <= 100; i++) {
        string theLoai = (i <= 10) ? "Khoa hoc" : ((i <= 40) ? "Van hoc" : "Thieu nhi");
        hienTai->tiep = taoSach(i, "Sach" + to_string(i), "TacGia" + to_string(i), theLoai, 0, "");
        hienTai = hienTai->tiep;
    }
    
    return dau;
}

void muonSach(Sach* dau, int ma, string khachHang) {
    Sach* hienTai = dau;
    while (hienTai != nullptr) {
        if (hienTai->ma == ma && hienTai->tinhTrang == 0) {
            hienTai->tinhTrang = 1;
            hienTai->khachHang = khachHang;
            cout << "Sach " << hienTai->ma << " da duoc cho muon cho " << khachHang << endl;
            return;
        }
        hienTai = hienTai->tiep;
    }
    cout << "Sach " << ma << " khong san co de muon." << endl;
}

void traSach(Sach* dau, int ma) {
    Sach* hienTai = dau;
    while (hienTai != nullptr) {
        if (hienTai->ma == ma && hienTai->tinhTrang == 1) {
            hienTai->tinhTrang = 0;
            hienTai->khachHang = "";
            cout << "Sach " << hienTai->ma << " da duoc tra lai." << endl;
            return;
        }
        hienTai = hienTai->tiep;
    }
    cout << "Sach " << ma << " hien khong duoc muon." << endl;
}

void danhSachSachThieuNhi(Sach* dau) {
    Sach* hienTai = dau;
    cout << "Sach Thieu nhi con san co:\n";
    while (hienTai != nullptr) {
        if (hienTai->theLoai == "Thieu nhi" && hienTai->tinhTrang == 0) {
            cout << "Ma: " << hienTai->ma << ", Ten: " << hienTai->ten << ", Tac gia: " << hienTai->tacGia << endl;
        }
        hienTai = hienTai->tiep;
    }
}

void nhapDuLieuMuonSach(Sach* dau) {
    int maSach;
    string tenKhachHang;
    
    cout << "Nhap ma sach muon: ";
    cin >> maSach;
    
    cout << "Nhap ten khach hang: ";
    cin.ignore(); // Xoa bo dem dau vao
    getline(cin, tenKhachHang);
    
    muonSach(dau, maSach, tenKhachHang);
}

void nhapDuLieuTraSach(Sach* dau) {
    int maSach;
    
    cout << "Nhap ma sach tra: ";
    cin >> maSach;
    
    traSach(dau, maSach);
}

void inToanBoDanhSach(Sach* dau) {
    Sach* hienTai = dau;
    cout << "Toan bo Sach:\n";
    while (hienTai != nullptr) {
        cout << "Ma: " << hienTai->ma << ", Ten: " << hienTai->ten << ", Tac gia: " << hienTai->tacGia
             << ", The loai: " << hienTai->theLoai << ", Tinh trang: " << ((hienTai->tinhTrang == 0) ? "San co" : "Da cho muon")
             << ", Khach hang: " << hienTai->khachHang << endl;
        hienTai = hienTai->tiep;
    }
}

void inMenu() {
    cout << "\nMenu:\n";
    cout << "1. Muon Sach\n";
    cout << "2. Tra Sach\n";
    cout << "3. Danh Sach Sach Thieu nhi\n";
    cout << "4. In Toan bo Sach\n";
    cout << "5. Thoat\n";
}

int main() {
    Sach* cuaHangSach = khoiTaoCuaHangSach();
    
    int luaChon;
    do {
        inMenu();
        cout << "Nhap lua chon cua ban: ";
        cin >> luaChon;

        switch (luaChon) {
            case 1:
                nhapDuLieuMuonSach(cuaHangSach);
                break;
            case 2:
                nhapDuLieuTraSach(cuaHangSach);
                break;
            case 3:
                danhSachSachThieuNhi(cuaHangSach);
                break;
            case 4:
                inToanBoDanhSach(cuaHangSach);
                break;
            case 5:
                cout << "Ket thuc chuong trinh.\n";
                break;
            default:
                cout << "Lua chon khong hop le. Vui long thu lai.\n";
        }
    } while (luaChon != 5);

    // Giai phong bo nho khi ket thuc chuong trinh
    Sach* hienTai = cuaHangSach;
    while (hienTai != nullptr) {
        Sach* sachTiepTheo = hienTai->tiep;
        delete hienTai;
        hienTai = sachTiepTheo;
    }

    return 0;
}
