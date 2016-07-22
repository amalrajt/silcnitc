decl
type
queue {
	integer value;
	queue next;
}
endtype
decl
	integer initialize(integer strt;);
	integer alloc();
	integer free(integer position;);
	integer initializeQueue(integer strt;);
	integer enque(queue &qvar;integer expr;);
	integer deque(queue &qvar;);
	integer allocQueue();
	integer freeQueue(integer position;);
enddecl

integer initialize(integer strt;){
	decl
		integer p,r;
	enddecl
	begin
		p = 0;
		while(p<100)do
			r = writemem(strt+(p*10)+9,0);
			p = p+1;
		endwhile;	
		return 0;
	end
}

integer alloc(){
	decl
		integer p,r,value,strt;
	enddecl
	begin
		strt = 0;
		value = 0;
		p = 0;
		while(p<100)do
			r = readmem(strt+(p*10)+9);
			if(r==0)then
				r = writemem(strt+(p*10)+9,1);
				value = strt+(p*10);
				return value;
			endif;
			p = p+1;
		endwhile;	
		return value;
	end
}

integer initializeQueue(integer strt;){
	decl
		integer p,r;
	enddecl
	begin
		p = 0;
		strt = 600;
		while(p<100)do
			r = writemem(strt+(p*3)+2,0);
			p = p+1;
		endwhile;
		return 0;
	end
}

integer allocQueue(){
	decl
		integer p,r,value,strt;
	enddecl
	begin
		strt = 600;
		value = 0;
		p = 0;
		while(p<100)do
			r = readmem(strt+(p*3)+2);
			if(r==0)then
				r = writemem(strt+(p*3)+2,1);
				value = strt+(p*3);
				return value;
			endif;
			p = p+1;
		endwhile;	
		return value;
	end
}

integer freeQueue(integer position;){
	decl
		integer p,r,value;
	enddecl
	begin
		value = 0;
		r = writemem(position+2,0);
		return value;
	end
}

integer enque(queue &qvar;integer expr;){
	decl
		integer value;
		queue new,temp;
	enddecl
	begin
		new = allocQueue();
		new.value = expr;
		if(qvar == 0)then
			qvar = new;
		else
			temp = qvar;
			while(temp.next > 0)do
				temp = temp.next;
			endwhile;
			temp.next = new;
		endif;
		return value;
	end
}

integer deque(queue &qvar;){
	decl
		integer value;
	enddecl
	begin
		value = qvar.value;
		return value;
	end
}

integer free(integer position;){
	decl
		integer p,r,value;
	enddecl
	begin
		value = 0;
		r = writemem(position+9,0);
		return value;
	end
}
end