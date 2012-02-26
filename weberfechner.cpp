#include <iostream>
#include <fstream>
using namespace std;

// 刻み幅
#define h 10
// 定数k
#define k_init 20
// 電圧
#define S_init 50
// 反応時間
#define R_init 180
// 初期電圧
#define S_start 50
// 終了電圧
#define S_finish 550

// ウェーバー・フェヒナー則
double f(double X){

        return(k_init/X);

}

// ルンゲ・クッタ法
void runge(){

        double x, y, x2, y2, x3, y3, s1 ,s2, s3, s4;
        // 初期値代入
        int i = S_start;
        x = S_init;
        y = R_init;

        // ファイルを開く
        ofstream out("weberfechner.dat");

        // エラー処理
        if(!out)
        {
                cout << "Cannot open file.\n";
        }

        do{
                // ファイルに解を出力
                out << i << " " << y << endl;

                // ルンゲ・クッタ法の実行
                s1 = f(x);
                s2 = f(x + h / 2.0);
                s3 = f(x + h / 2.0);
                s4 = f(x + h);
                y += h * (s1 + 2.0 * s2 + 2.0 * s3 + s4) / 6.0;
                x += h;

                i += h;

        }while(i <= S_finish);

        out.close();

}

int main(){

        runge();

        return 0;
}
