
// 2015/06/13
// ポインタとスマートポインタ
// コンソールアプリケーションによる動作確認サンプル

#include <iostream>
#include <string>

// スマートポインタの宣言に必要なインクルードファイル
#include <memory>


void Create(const std::string& name) { std::cout << "Create." << name << std::endl; }
void Delete(const std::string& name) { std::cout << "Delete." << name << std::endl; }


class Object {
public:
  Object(const std::string& n = "object") : name_(n) { Create(name_); }
  ~Object() { Delete(name_); }
  //virtual ~Object() { std::cout << "Delete.Object" << std::endl; }

protected:
  std::string name_;
};


class Player : public Object {
public:
  Player() : Object("player") { Create(name_); }
  ~Player() { Delete(name_); }
};


class Enemy : public Object {
public:
  Enemy() : Object("enemy") { Create(name_); }
  ~Enemy() { Delete(name_); }
};


int main() {
  const auto endl = [] { std::cout << std::endl; };

  // 1. ポインタの宣言、初期化と解放
  // NOTICE: コンストラクタ（と、デストラクタ）が呼ばれるタイミングを知る
  {
    std::cout << "ポインタ" << std::endl;

    // 親クラスのポインタに親クラスのデータを入れる
    Object* obj = new Object();
    delete obj;
    endl();

    // 親クラスのポインタに子クラスのデータを入れる
    obj = new Player();
    delete obj;
    endl();
  }
  // まとめ
  // . 継承関係にあるクラスを扱う場合に有効
  // . メモリの解放忘れに注意

  // 2. スマートポインタの種類
  // NOTICE: メモリを自動的に解放してくれるので、解放忘れの心配がない
  {
    std::cout << "スマートポインタ" << std::endl;

    // std::unique_ptr  ユニークポインタ
    {
      std::cout << ">> ユニークポインタ" << std::endl;
      Object* obj;   // ユニークではないポインタ

      std::unique_ptr<Object> unique_obj = std::make_unique<Object>();

      // std::make_unique = スマートポインタ版の new
      unique_obj = std::unique_ptr<Enemy>();
      endl();
    }
    
    // std::shared_ptr  シェアードポインタ
    {
      std::cout << ">> シェアードポインタ" << std::endl;
      std::shared_ptr<Object> shared_obj_1 = std::make_shared<Player>();
      std::shared_ptr<Object> shared_obj_2;
      shared_obj_2 = shared_obj_1;
    }
    endl();

    // 補足: その他のスマートポインタについて
    /*
     * std::auto_ptr  オートポインタ
     *   一番最初に作られたスマートポインタ。
     *   挙動に致命的な欠陥があったために、ユニークポインタなど、
     *   その他のスマートポインタが作られることになった。
     *   現在では、まず使われないスマートポインタ。
     *
     * std::weak_ptr  ウィークポインタ
     *   通常、これだけで使われることはない。
     *   基本的に、シェアードポインタと一緒に使う。
     *   マルチスレッド処理をするときに強い。
     */
  }
  // まとめ
  // . 自動的にメモリ解放してくれる、比較的安全なポインタ
  // . std::shared_ptr が使い勝手がよく便利
}
