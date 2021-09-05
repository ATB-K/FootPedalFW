# FootPedalFW

## 説明
電子ピアノ用のフットペダルをUSBフットペダル化するデバイスの設計図とFWです。

## 使い方 
デバイスの使い方はUSBぶっ刺すだけ。</br>
フットペダルの割り当てキーを切り替えたい場合は「キー割り当て」と「ペダルごとの動作定義」のコメント箇所を修正すれば良い。</br>
書き換える値は下記を参照しながら頑張ってください。
- [キーボード (ASCII)](https://www.asciitable.com/)
- [キーボード (拡張)](https://www.arduino.cc/reference/en/language/functions/usb/keyboard/keyboardmodifiers/)
- [マウス](https://www.arduino.cc/reference/en/language/functions/usb/mouse/mousepress/)

## デバイス設計

### パーツ
|部品名|個数|
| --- | --- |
|Arduino Micro|1|
|モノラルジャック オープンタイプ|3|
|デュポンワイヤー(メス)|5～10|
|プラスチックケース|1|

### 配線図
<img src="https://raw.githubusercontent.com/ATB-K/FootPedalFW/master/doc/image/device.jpg" style=width:600px>

## FW焼き込み方法
1. [Arduino IDE](https://www.arduino.cc/en/software) をインストール。
2. 「footpedal_fw.ino」をダウンロードし、キー割り当てを任意の値に修正。
3. ボード設定をArduino Microに変更する。</br><img src="https://raw.githubusercontent.com/ATB-K/FootPedalFW/master/doc/image/board_select.png" style=width:600px>
4. シリアルポートを接続したArduino Microに変更する。</br><img src="https://raw.githubusercontent.com/ATB-K/FootPedalFW/master/doc/image/port_select.png" style=width:600px>
5. 「マイコンボードの書き込む」を押下してFWを焼く。</br><img src="https://raw.githubusercontent.com/ATB-K/FootPedalFW/master/doc/image/write_fw.png">

## Author

[ATB](https://github.com/ATB-K)