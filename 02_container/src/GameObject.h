
#pragma once
#include "Common.hpp"
#include <list>
#include <memory>


class Env {
public:

  // シングルトンと呼ばれるデザインパターン
  // TIPS: プログラム実行中は絶対に１つしかないことを保証する
  static AppEnv& get() {
    static AppEnv s_env(common::WIDTH, common::HEIGHT, false, true);
    return s_env;
  }

private:
  Env() = default;
};


// 別名宣言
typedef std::shared_ptr<class GameObject>  pObject;
typedef std::list<pObject>                 ObjectList;

// 継承元になる親クラス
// TIPS:
//  親クラスのポインタを使ってコンテナを回す場合、
//  必ず仮想関数を用意すること
class GameObject {
public:

  // コンストラクタ
  // TIPS: 何もしないことを明示的にする
  GameObject() = default;

  // 仮想デストラクタ
  virtual ~GameObject() = default;

  // 仮想関数
  // TIPS: 親クラスのポインタから、子供クラスの機能を使えるようにする
  // TIPS: 気になったら、virtual を外してプログラムを実行してみよう
  virtual void update() {}
  virtual void draw() {}

  // コンテナ（シングルトン）
  // TIPS: static をつけた関数は、どこからでも使えるようになる
  static std::list<pObject>& getObject() {
    static ObjectList s_list;
    return s_list;
  }

  // 画面外のショットを消す処理 (cpp)
  static void objectKill();

protected:
  Texture texture_;
  Vec2f size_;

  Vec2f pos_;
  int   dir_;         // 方向
  float vel_;         // 速度

  short blink_;       // 自機の点滅状態
  short time_;        // 点滅タイマー

  short dead_time_;   // 死亡判定

  // 向きを計算して、回転量を返す
  const float getDirection() const { return dir_ * M_PI / 2; }

  // 移動方向と速度の計算 (cpp)
  const Vec2f getVelocity();

  // 死んでるか判定
  const bool isDead() const { return dead_time_ == 0; }
};


class Shot : public GameObject {
public:

  // コンストラクタ (cpp)
  // TIPS: 発射されたときに、自機の情報を受け取る
  Shot(const Vec2f&, const int);

  // 自分の位置を更新する
  void update() {
    pos_ += getVelocity();
    removeCheck();
  }

  // 表示
  void draw() {
    drawTextureBox(pos_.x(), pos_.y(), size_.x(), size_.y(),
                   0, 0, size_.x(), size_.y(),
                   texture_, Color::white,
                   getDirection(),
                   Vec2f::Ones(), size_ / 2);
  }

private:

  // 自分（ショット）が画面外に出たかチェックする
  void removeCheck() {
    const Vec2f w_size(common::WIDTH, common::HEIGHT);

    // 画面外なら死んだことにする = 削除できるようにする
    if (pos_.x() < -w_size.x() / 2 || pos_.x() > w_size.x() / 2 ||
        pos_.y() < -w_size.y() / 2 || pos_.y() > w_size.y() / 2) {
      dead_time_ = 0;
    }
  }
};


class Player : public GameObject {
public:

  // (cpp)
  Player();

  void update();
  void draw();

private:

  // 画像の切り替え
  void blinkUpdate() {
    blink_ = (time_ / 15) % 2;

    ++time_;
    if (time_ < 60) return;

    time_ = 0;
  }
};
