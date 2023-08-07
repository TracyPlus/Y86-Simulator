var file;
var filename;
var jsonname;
var i=0;
var Rax=0,Rcx=0,Rdx=0,Rbx=0,Rsp=0,Rbp=0,Rsi=0,Rdi=0;
var R8=0,R9=0,R10=0,R11=0,R12=0,R13=0,R14=0;
var Pc=0,Stat=0,Cc=0;
var Memory=0;
var json='';
var reader=new FileReader();
var Order='';
var request = new XMLHttpRequest();
const button=document.querySelector('button');
//点击“next”跳到下一条指令
button.onclick=function(){
    Rax=json[i]["REG"]["rax"];
    document.getElementById("rax").innerHTML="rax:"+Rax;
    Rcx=json[i]["REG"]["rcx"];
    document.getElementById("rcx").innerHTML="rcx:"+Rcx;
    Rdx=json[i]["REG"]["rdx"];
    document.getElementById("rdx").innerHTML="rdx:"+Rdx;
    Rbx=json[i]["REG"]["rbx"];
    document.getElementById("rbx").innerHTML="rbx:"+Rbx;
    Rsp=json[i]["REG"]["rsp"];
    document.getElementById("rsp").innerHTML="rsp:"+Rsp;
    Rbp=json[i]["REG"]["rbp"];
    document.getElementById("rbp").innerHTML="rbp:"+Rbp;
    Rsi=json[i]["REG"]["rsi"];
    document.getElementById("rsi").innerHTML="rsi:"+Rsi;
    Rdi=json[i]["REG"]["rdi"];
    document.getElementById("rdi").innerHTML="rdi:"+Rdi;
    R8=json[i]["REG"]["r8"];
    document.getElementById("r8").innerHTML="r8:"+R8;
    R9=json[i]["REG"]["r9"];
    document.getElementById("r9").innerHTML="r9:"+R9;
    R10=json[i]["REG"]["r10"];
    document.getElementById("r10").innerHTML="r10:"+R10;
    R11=json[i]["REG"]["r11"];
    document.getElementById("r11").innerHTML="r11:"+R11;
    R12=json[i]["REG"]["r12"];
    document.getElementById("r12").innerHTML="r12:"+R12;
    R13=json[i]["REG"]["r13"];
    document.getElementById("r13").innerHTML="r13:"+R13;
    R14=json[i]["REG"]["r14"];
    document.getElementById("r14").innerHTML="r14:"+R14;
    Pc=json[i]["PC"];
    document.getElementById("PC").innerHTML="PC:"+Pc;
    Stat=json[i]["STAT"];
    document.getElementById("STAT").innerHTML="STAT:"+Stat;
    if(Stat!=1){
        EndCondition();
        return;
    }
    Cc=JSON.stringify(json[i]["CC"],null,2);
    document.getElementById("CC").innerHTML="CC:"+Cc;
    Memory=JSON.stringify(json[i]["MEM"],null,2);
    document.getElementById("memory").innerHTML="memory:"+Memory;
    Order=json[i]["ORDER"];
    document.getElementById("OP").innerHTML="OP:"+Order;
    i++;
}
//遇到stat不为1的时候切换背景，表示出错, 程序显示完毕
function EndCondition(){
    alert("All men have the stars, but they are not the same things for different people.");
    let myImage = document.querySelector('img');
    myImage.setAttribute ('src','day.jpg');
    return;
}
//切换文件时初始状态
function Initial(){
    let myImage = document.querySelector('img');
    myImage.setAttribute ('src','bgn.jpg');
    document.getElementById("rax").innerHTML="rax:";
    document.getElementById("rcx").innerHTML="rcx:";
    document.getElementById("rdx").innerHTML="rdx:";
    document.getElementById("rbx").innerHTML="rbx:";
    document.getElementById("rsp").innerHTML="rsp:";
    document.getElementById("rbp").innerHTML="rbp:";
    document.getElementById("rsi").innerHTML="rsi:";
    document.getElementById("rdi").innerHTML="rdi:";
    document.getElementById("r8").innerHTML="r8:";
    document.getElementById("r9").innerHTML="r9:";
    document.getElementById("r10").innerHTML="r10:";
    document.getElementById("r11").innerHTML="r11:";
    document.getElementById("r12").innerHTML="r12:";
    document.getElementById("r13").innerHTML="r13:";
    document.getElementById("r14").innerHTML="r14:";
    document.getElementById("PC").innerHTML="PC:";
    document.getElementById("STAT").innerHTML="STAT:";
    document.getElementById("CC").innerHTML="CC:";
    document.getElementById("memory").innerHTML="memory:";
    i=0;
};

function filechange(){
    //获取选择的文件名
    file=document.getElementById("file").files[0];
    filename=file.name;
    jsonname=filename.replace('.yo','.json');
    //找到对应json文件
    request = new XMLHttpRequest();
    url="http://localhost:8000/answers/"+jsonname;
    request.open('GET', url);
    request.responseType = 'json';
    request.send();
    request.onload=function(){
        json=request.response;
    }
    Initial();
}
