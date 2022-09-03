
printfはリターン -1を返す
printf  return -1



size_t	-> int
size_t	-> ssize_t

va_copyを使ってみる！！



ft_proc_per()

p
u
を分けるか
longをつかう




to 16

// putnumの書き方
// num = 1234567
// recursive 再帰関数
// 固定長配列を作ってそこに格納していく
// 前から入れていく-> 桁数を調べる -> 100000のくらいまである
桁数分だけmallocする
1234567 / 1000000 -> 1
1234567 / 100000 -> 12 % 10
1234567 / 10000 -> 123 % 100



size_t ft_putnum_base(unsined long num, char *base)
{
	size_t base_len;// ナン進数か0123456789abcdef
	size_t len;//桁数->printfが出力した文字列を返すのに必要
	size_t exp;//exponential -> 指数 -> 何乗か-> 何桁か -> base_len^exp

	base_len = ft_strlen(base);
	exp = 1; // base_len^0
	while (num >= base_len *exp)
		exp *= base_len;
	while(exp)
	{
		write(1, &base[num / exp % base_len], 1);
		num %
	}
	
}




必ずapをアドレス渡しにする

else
	;

トラップ表現
