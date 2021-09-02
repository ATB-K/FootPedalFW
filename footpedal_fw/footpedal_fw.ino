#include <Mouse.h>
#include <Keyboard.h>

// キー割り当て
const int BTN_1 = 0x80;
const int BTN_2 = MOUSE_RIGHT;
const int BTN_3 = MOUSE_LEFT;

// 定数
const int BTN_PUSH    = 0;
const int BTN_RELEASE = 1;
const int PIN[] = {8, 9, 10};                  // 利用PIN定義
const int PIN_NUM  = sizeof(PIN) / sizeof(int);// 利用PINの数

// ペダルごとの動作定義
static void push_btn_1(void){ Keyboard.press( BTN_1 ); }
static void push_btn_2(void){ Mouse.press( BTN_2 ); }
static void push_btn_3(void){ Mouse.press( BTN_3 ); }
static void release_btn_1(void){ Keyboard.release( BTN_1 ); }
static void release_btn_2(void){ Mouse.release( BTN_2 ); }
static void release_btn_3(void){ Mouse.release( BTN_3 ); }

void (* const FUNC_BTNS[PIN_NUM][2])(void) = {
    {push_btn_1, release_btn_1},
    {push_btn_2, release_btn_2},
    {push_btn_3, release_btn_3}
};

// グローバル変数
int BEFORE_VALUE[PIN_NUM] = {HIGH, HIGH, HIGH};  // 押下情報記録用 (High -> Low検知式の為、初期値High)

/*
 * 通電時の初期化処理
 */
void setup(){
  // ピン設定
  for (int i=0 ; i < PIN_NUM ; i++) {
      pinMode( PIN[i], INPUT_PULLUP );
  }
}

/*
 * 通電中のループ処理
 */
void loop(){
  for (int i=0 ; i < PIN_NUM ; i++) {

    // ピン値読み取り
    int value = digitalRead( PIN[i] );

    if (value == LOW) {
      if (BEFORE_VALUE[i] == HIGH) {
        // High -> Lowの場合
        FUNC_BTNS[i][BTN_PUSH]();

        // ボタンの変化を記録
        BEFORE_VALUE[i] = value;
      } else {
        // Low -> Lowの場合
        // Do Nothing
      }
    } else {
      if (BEFORE_VALUE[i] == LOW) {
        // Low -> Highの場合
        FUNC_BTNS[i][BTN_RELEASE]();

        // ボタンの変化を記録
        BEFORE_VALUE[i] = value;
      } else {
        // High -> Highの場合
        // Do Nothing
      }
    }
  }

  // ポーリング間隔
  delay( 10 );
}
