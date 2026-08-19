int k, m = 111;
b() {
	k = 10;
}
main () 
{
	int j = 5, i = 10;
label:
	j = a();
	k = i + j;
	b();
	printf("hi\n");
	goto label;	
}

