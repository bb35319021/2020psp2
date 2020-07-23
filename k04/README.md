# 課題4 レポート

bb35319021 久保田諭

## 課題

[../sample/heights.csv]は標本全体（男性と女性合わせた14人）のデータをまとめたものである．
一方，[../sample/IDs.csv]は標本14人の学籍番号（身長データと同じ順番）である．
学籍番号を尋ねて，その学籍番号のデータがリストにあれば，学籍番号，身長，性別のデータを表示し，リストになければ，「No data」と表示せよ．

この二つのファイルを読み取り，学籍番号，身長，性別の3つをメンバーとする構造体の配列で管理するとよい．

## ソースコードの説明

6 構造体の宣言

25~ ファイルの読み取り

61~ 入力した学生番号と同じ番号があったらその番号の情報（番号、性別、身長）を出力

73 入力した番号がなかったらNo data

77~ ファイルを閉じる

## 入出力結果

例えば，ID 45313125のデータを調べたいとき，

```
input the filename of sample height:../sample/heights.csv
input the filename of sample ID:../sample/IDs.csv
Which ID's data do you want? :45313125

NO data
```

例えば，ID 45313124のデータを調べたいとき，

```
input the filename of sample height:../sample/heights.csv
input the filename of sample ID:../sample/IDs.csv
Which ID's data do you want? :45313124

NO data
```

## 修正履歴
[comment #20200723]
- l.49 書式指定子が正しくありません. IDを取ってくるので, 第3引数も違うと思います. 
また, 第4引数が不要です. 

