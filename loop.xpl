begin
decl
int b,a[20];
enddecl

b=0;
while(b<20) do
	a[b] = b;
	b=b+1;
endwhile;

b=0;
while(b<20) do	
	write(a[b]);
	b=b+1;
endwhile;

end