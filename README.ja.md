<h1 align="center">42 Tokyo — Common Core</h1>

<p align="center">
  42 Common Core でソフトウェアエンジニアリングを学ぶ過程の記録です。
</p>

<p align="center">
  <img src="https://img.shields.io/badge/42-Tokyo-000000?style=flat-square" alt="42 Tokyo">
  <img src="https://img.shields.io/badge/Language-C-00599C?style=flat-square&logo=c&logoColor=white" alt="C">
  <img src="https://img.shields.io/badge/2026-Present-555555?style=flat-square" alt="2026年〜現在">
</p>

[English](README.md) | 日本語

## 42 について

[42 Tokyo](https://42tokyo.jp/) は、プロジェクトを通じて学生同士で学び合う、
ソフトウェアエンジニアリングの学校です。

学生は自主的な調査、実践的なプログラミング課題、協働、相互評価を通じて学びます。

## Common Core について

**Common Core** は、プログラミング、アルゴリズム、Unix システム、
ソフトウェアエンジニアリング、問題解決を学ぶ 42 の基礎カリキュラムです。

このリポジトリには、カリキュラムで取り組んだプロジェクトと学習の進捗を記録しています。

## プロジェクト

| プロジェクト | 説明 | 課題文 |
|:---|:---|:---:|
| [Libft](./Libft/README.ja.md) | 標準ライブラリ関数の再実装と補助関数の作成を通じて、再利用可能な C ライブラリを構築します | [PDF](./subjects/Libft.pdf) |
| [ft_printf](./ft_printf/README.ja.md) | 可変長引数と書式解析を使い、10進数・16進数の出力など、`printf` の基本的な変換処理を再実装します | [PDF](./subjects/ft_printf.pdf) |
| [get_next_line](./get_next_line/README.ja.md) | バッファを使った読み込み、static 変数、動的メモリ確保を使い、ファイルや標準入力から1行ずつ読み込みます | [PDF](./subjects/get_next_line.pdf) |
| [push_swap](./push_swap/README.ja.md) | 2 つのスタックと 11 種類の操作で整数を並べ替えます。入力の乱れ度に応じて方法を選び、ボーナス版チェッカーで結果を検証します | [PDF](./subjects/push_swap.pdf) |

## テスト

Libft と ft_printf のテスターは、別のリポジトリで管理しています。
使用方法は [42 Common Core Tests の README](https://github.com/andrei-bozhek/42-Common-Core-Tests/blob/main/README.md) を参照してください。

Push_swap の README には、テスト入力の生成、操作数の計測、ボーナス版と課題付属の Linux 版チェッカーによる検証の手順があります。[Push_swap のテスト手順](./push_swap/README.ja.md#課題付属の-linux-版チェッカーで確認する)

## スキルと技術

- **言語:** C
- **ツール:** Git、Make、Unix シェル
- **概念:** メモリ管理、ポインタ、アルゴリズム、モジュール化、可変長引数、書式付き出力、ファイルディスクリプタ、バッファを使った読み込み、static 変数、スタック操作、適応型ソート、計算量

新しいプロジェクトを完了するたびに、この項目も更新していきます。

## リポジトリの構成

各プロジェクトのディレクトリには、ソースコードと英語・日本語の README があります。
Makefile が必要なプロジェクトには、そのディレクトリ内に Makefile を置いています。
課題文の PDF は、共通の [subjects](./subjects/) ディレクトリに保存しています。

## Common Core 以前の学習

Common Core を始める前に、短期集中プログラムの **42 Tokyo C Piscine** を修了しました。

[42 Piscine のリポジトリを見る](https://github.com/andrei-bozhek/42-Piscine)
