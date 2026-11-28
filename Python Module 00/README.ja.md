*This project has been created as part of the 42 curriculum by abozhek.*

[English](README.md) | 日本語

# Python Module 00 — Growing Code

## 概要

Growing Code は、コミュニティ菜園のデータを題材に Python の基礎を学ぶ課題です。
8 つの演習を通じて、コンソール入出力、整数の計算、条件分岐、ループ、再帰、型注釈を扱います。

## 演習

| 演習 | ソースコード | 内容 |
| --- | --- | --- |
| ex0 | [`ft_hello_garden.py`](ex0/ft_hello_garden.py) | あいさつのメッセージを表示します。 |
| ex1 | [`ft_garden_name.py`](ex1/ft_garden_name.py) | 菜園の名前を入力し、状態を示すメッセージとともに表示します。 |
| ex2 | [`ft_plot_area.py`](ex2/ft_plot_area.py) | 長方形の区画の面積を計算します。 |
| ex3 | [`ft_harvest_total.py`](ex3/ft_harvest_total.py) | 3 日分の収穫量を合計します。 |
| ex4 | [`ft_plant_age.py`](ex4/ft_plant_age.py) | 植物が育ち始めてから 60 日を超えたかを判定します。 |
| ex5 | [`ft_water_reminder.py`](ex5/ft_water_reminder.py) | 最後の水やりから 2 日を超えた場合に水やりを促します。 |
| ex6 | [ループ版](ex6/ft_count_harvest_iterative.py)、[再帰版](ex6/ft_count_harvest_recursive.py) | 1 日目から収穫日まで順に表示します。ループ版と再帰版の出力は同じです。 |
| ex7 | [`ft_seed_inventory.py`](ex7/ft_seed_inventory.py) | 型注釈を付けた関数で、種の在庫情報を単位に応じて表示します。 |

## 使用方法

Python 3.10 以降を使用します。リポジトリのルートから次のコマンドを実行すると、
各演習のディレクトリをモジュールの検索パスに加えて、付属のテストメニューを起動できます。

```sh
cd "Python Module 00"
PYTHONPATH=ex0:ex1:ex2:ex3:ex4:ex5:ex6:ex7 python3 main.py
```

`0`〜`7` で個別の演習、`a` で全演習を試せます。`6` を選ぶと、ループ版と再帰版で
日数を 1 回ずつ入力します。`7` では、袋数、グラム数、面積、未対応の単位のサンプルが使われます。

### コードの確認

`flake8` と `mypy` をインストールした環境で、モジュールのディレクトリから実行します。

```sh
flake8 ex[0-7]/ft_*.py
mypy ex7/ft_seed_inventory.py
```

## 参考資料

- **42 Growing Code の課題文** — 各演習の要件と出力例。[PDF](../subjects/Python%20Module%2000.pdf)
- **W3Schools** — コード例と練習問題で Python の基礎を学べます。[Python チュートリアル（英語）](https://www.w3schools.com/python/)

### AI の利用

AIは使用していません。
