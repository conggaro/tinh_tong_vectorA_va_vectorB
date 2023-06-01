// Yêu cầu:
// 1. cho số nguyên A (có thể có 100 chữ số)
// 2. cho số nguyên B (có thể có 100 chữ số)
// 3. viết chương trình cộng 2 số nguyên trên
// 4. hiển thị ra màn hình

// Chú ý: trong chương trình cần sử dụng kiểu dữ liệu vector 

#include <iostream>
#include <vector>
using namespace std;

// hàm hiển thị A
void HienThi_A(vector<int> v){
    cout << "So A la: ";
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i];
    }
    cout << endl;
}

// hàm hiển thị B
void HienThi_B(vector<int> v){
    cout << "So B la: ";
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i];
    }
    cout << endl;
}

// hàm hiển thị B
void HienThi_Tong(vector<int> v){
    cout << "Tong A va B la: ";
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i];
    }
    cout << endl;
}

// hàm cộng số A và số B
vector<int> Tinh_Tong_A_B(vector<int> A, vector<int> B){
    vector<int> v_tong;
    int tinh_tong = 0;
    int bao_hieu = 0; // dùng để xác định xem số đó có nhớ 1 không
    int data = 0;

    bool kiemTra1;
    bool kiemTra2;

    // viết code tiền xử lý
    // gọi là để phân loại độ dài
    // Trường hợp 1: A.size() == B.size()
    // Trường hợp 2: A.size() > B.size()
    // Trường hợp 3: A.size() < B.size()

    // đây là code tiền xử lý
    bool kiemTra_sizeA_bang_sizeB = A.size() == B.size() ? true : false;
    bool kiemTra_sizeA_lon_hon_sizeB = A.size() > B.size() ? true : false;
    bool kiemTra_sizeA_nho_hon_sizeB = A.size() < B.size() ? true : false;

    // bây giờ sẽ kiểm tra điều kiện rẽ nhánh
    if(kiemTra_sizeA_bang_sizeB){
        // viết code xử lý
        for(int i = A.size() - 1; i >= 0; i--){
            if(bao_hieu == 0)
            {
                tinh_tong = A[i] + B[i];
            }else if(bao_hieu == 1){
                tinh_tong = A[i] + B[i];
                tinh_tong = tinh_tong + 1;
            }            
            
            if(tinh_tong < 10){
                data = tinh_tong;
                v_tong.push_back(data);
                bao_hieu = 0;

            }else if(tinh_tong >= 10){
                data = tinh_tong % 10;
                v_tong.push_back(data);
                bao_hieu = 1;
            }
        }

        kiemTra1 = bao_hieu == 1 ? true : false;
        kiemTra2 = A.size() == B.size() ? true : false;

        if (kiemTra1 == true && kiemTra2 == true)
        {
            v_tong.push_back(1);
        }
        
    }else if(kiemTra_sizeA_lon_hon_sizeB){
        vector<int> Clone;
        for(int i = 0; i < A.size() - B.size(); i++){
            Clone.push_back(0);
        }
        
        for (int i = 0; i < B.size(); i++)
        {
            Clone.push_back(B[i]);
        }
        
        // viết code xử lý
        for(int i = A.size() - 1; i >= 0; i--){
            if(bao_hieu == 0){
                tinh_tong = A[i] + Clone[i];
            }else if(bao_hieu == 1){
                tinh_tong = A[i] + Clone[i];
                tinh_tong = tinh_tong + 1;
            }
                
            if(tinh_tong < 10){
                data = tinh_tong;
                v_tong.push_back(data);
                bao_hieu = 0;

            }else if(tinh_tong >= 10){
                data = tinh_tong % 10;
                v_tong.push_back(data);
                bao_hieu = 1;
            }                       
        }

        kiemTra1 = bao_hieu == 1 ? true : false;
        kiemTra2 = A.size() == Clone.size() ? true : false;

        if (kiemTra1 == true && kiemTra2 == true)
        {
            v_tong.push_back(1);
        }

    }else if(kiemTra_sizeA_nho_hon_sizeB){
        vector<int> Clone;
        for(int i = 0; i < B.size() - A.size(); i++){
            Clone.push_back(0);
        }
        
        for (int i = 0; i < A.size(); i++)
        {
            Clone.push_back(A[i]);
        }
        
        // viết code xử lý
        for(int i = B.size() - 1; i >= 0; i--){
            if(bao_hieu == 0){
                tinh_tong = B[i] + Clone[i];
            }else if(bao_hieu == 1){
                tinh_tong = B[i] + Clone[i];
                tinh_tong = tinh_tong + 1;
            }
                
            if(tinh_tong < 10){
                data = tinh_tong;
                v_tong.push_back(data);
                bao_hieu = 0;

            }else if(tinh_tong >= 10){
                data = tinh_tong % 10;
                v_tong.push_back(data);
                bao_hieu = 1;
            }                       
        }

        kiemTra1 = bao_hieu == 1 ? true : false;
        kiemTra2 = B.size() == Clone.size() ? true : false;

        if (kiemTra1 == true && kiemTra2 == true)
        {
            v_tong.push_back(1);
        }
    }

    // lúc nào xong thì làm 1 cái hàm sắp xếp đảo ngược là được
    vector<int> ketQua;
    for (int i = v_tong.size() - 1; i >= 0; i--)
    {
        ketQua.push_back(v_tong[i]);
    }
    
    return ketQua;
}

int main(){
    vector<int> v_A;
    vector<int> v_B;

    // nhập số chữ số cho số A
    cout << "Nhap so chu so cho A: ";
    int so_chu_so_A;
    cin >> so_chu_so_A;

    // biến lưu từng số khi nhập vào của A là
    int data_A;

    // cơ chế của vector là vào trước, ra sau
    // ví dụ số "abcd" thì chữ số "a" sẽ được push_back() vào đầu tiên
    for(int i = 0; i < so_chu_so_A; i++){
        cout << "Nhap vao so thu \"" << i+1 << "\" cua A la: ";
        cin >> data_A;
        v_A.push_back(data_A);
    }

    // nhập số chữ số cho số B
    cout << "\nNhap so chu so cho B: ";
    int so_chu_so_B;
    cin >> so_chu_so_B;

    // biến lưu từng số khi nhập vào của B là
    int data_B;

    // cơ chế của vector là vào trước, ra sau
    // ví dụ số "abcd" thì chữ số "a" sẽ được push_back() vào đầu tiên
    for(int i = 0; i < so_chu_so_B; i++){
        cout << "Nhap vao so thu \"" << i+1 << "\" cua B la: ";
        cin >> data_B;
        v_B.push_back(data_B);
    }

    cout << endl;
    HienThi_A(v_A);
    HienThi_B(v_B);

    // hiển thị kết quả sau khi tính tổng
    cout << endl;
    vector<int> tong_A_B = Tinh_Tong_A_B(v_A, v_B);
    HienThi_Tong(tong_A_B);

    return 0;
}