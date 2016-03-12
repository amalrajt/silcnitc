decl
    integer x;  
    integer Func(integer &x;);  
enddecl

integer Func(integer &x;){
    decl
        integer t;
    enddecl
    
    begin
        if (x > 90) then
            t = 91;
        else
            t=x+11;
            t=Func(&t);
            t=t+1; 
            t=Func(&t);
        endif;
        return t;
    end
}

integer main(){
decl
    integer result;
enddecl
begin
    read(x);
    result = Func(&x);
    write(result);
    return 0;
end
}
end