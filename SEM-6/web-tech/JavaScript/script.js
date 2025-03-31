// Q.1 
function max() {
    var num1=parseInt(document.getElementById("num1").value);
    var num2=parseInt(document.getElementById("num2").value);

    let res=0;
	if (num1>num2){res= num1;}
    else {res= num2;}

    document.getElementById("result").innerHTML = res;
}

// Q.2
function max3() {
    var num1=parseInt(document.getElementById("n1").value);
    var num2=parseInt(document.getElementById("n2").value);
    var num3=parseInt(document.getElementById("n3").value);

    let res=0;
	if (num1>num2){res= num1;}
    if(num3>res){res=num3;}
    else {res= num2;}

    document.getElementById("result").innerHTML = res;
}//Harsh VM

//Q.3

function checkvowel() {
    var char=document.getElementById("vowel").value.toLowerCase();
    let res="False";

    const vo=["a","e","i","o","u"];
    for(let i=0;i<vo.length;i++){
        if(char==vo[i]){
            res="True";
            break;
        }
    }
    document.getElementById("result").innerHTML = res;
}

//Q.4 
function translateTxt(){
    var str=document.getElementById("rov").value.toLowerCase();
    let res="";
    for(let i=0;i<str.length;i++){
        if(str[i]=="a" || str[i]=="e" || str[i]=="i" || str[i]=="u" || str[i]=="o" || str[i]==" "){
            res+=str[i];
        }
        else{
            res+=str[i]+"o"+str[i];
        }
    }

    document.getElementById("result").innerHTML=res;
}//Harsh VM

//Q.5
function sums(){
    let arr=document.getElementById("nums").value.split(",");
    let res=0;
    for(let i=0;i<arr.length;i++){
        res+=parseInt(arr[i]);
    }
    document.getElementById("result").innerHTML=res;
}

function muls(){
    let arr=document.getElementById("nums").value.split(",");
    let res=1;
    for(let i=0;i<arr.length;i++){
        res*=parseInt(arr[i]);
    }
    document.getElementById("result").innerHTML=res;
}

//Q.6
function rever(){
    let str=document.getElementById("rev").value;
    let res="";
    for(let i=str.length-1;i>=0;i--){
        res+=str[i];
    }
    document.getElementById("result").innerHTML=res;
    console.log(res);
}//Harsh VM

//Q.7
function spanish(){
    let str=document.getElementById("spanish").value.split(" ");
    const dic={
        "merry":"god",
        "christmas":"jul",
        "and":"och",
        "happy":"gott",
        "new":"nytt",
        "year":"ar"
    }

    let res="";
    for(let i=0;i<str.length;i++){
        if(str[i] in dic){
            res+=dic[str[i]]+" ";
        }
        else{
            res="Not matching words!!"
        }
    }
    document.getElementById("result").innerHTML=res;
}//Harsh VM

//Q.8
function longest(){
    let arr=document.getElementById("longest").value.split(",");
    let res="";
    for(let i=0;i<arr.length;i++){
        if(arr[i].length>res.length){
            res=arr[i];
        }
    }

    document.getElementById("result").innerHTML=res+" : "+res.length;
}

//Q.9
function findlong(){
    let arr=document.getElementById("wd").value.split(",");
    let k=document.getElementById("inti").value;
    let res=[];

    for(let i=0;i<arr.length;i++){
        if(arr[i].length>parseInt(k)){
            res.push(arr[i]);
        }
    }
    document.getElementById("result").innerHTML=res;
}

//Q.10
function findfreq(){
    let str=document.getElementById("freq").value;
    let obj={}

    for(let i=0;i<str.length;i++){
        if(!(str[i] in obj)){
            obj[str[i]]=1;
        }
        else{
            obj[str[i]]+=1;
        }
    }
    document.getElementById("result").innerHTML=JSON.stringify(obj);
}//Harsh VM

//Q.11
function solve(){
    let res=0;
    let str=document.getElementById("equation").value;
    document.getElementById("result").innerHTML=eval(str);
}

//Q.12 only script
function getnames(){
    let names = [];
    while (true) {
        let name = prompt("Enter a name (or click Cancel to finish):");
        if (name === null) {
            break;
        }
        names.push(name);
    }
    names.sort();
    let orderedList = "<ol>";
    for (let i = 0; i < names.length; i++) 
    {orderedList += `<li>${names[i]}</li>`;}
    orderedList += "</ol>";
    document.getElementById("result").innerHTML = orderedList;
}//Harsh VM


//Q.13
function rand(){
    let k=parseInt(document.getElementById("rand").value);
    let arr=[];
    let avg=0;
    for(let i=0;i<k;i++){
        let x=Math.floor(Math.random()*100);
        arr.push(x);
        avg+=x;
    }
    avg/=k;

    document.getElementById("result").innerHTML=arr+"</br>"+"Avg:"+avg;
}

//Q.14
function formm() {
    let p1 = document.getElementById("pass1").value;
    let p2 = document.getElementById("pass2").value;

    if (p1 === p2) {
        alert("You can proceed!");
    } else {
        alert("Passwords are not the same!");
    }
}

//Q.15 and Q.16
function welcome(){
    alert("Welcome everyone!!!");
}//Harsh VM

//Q.17
function hometown(){
    let name=document.getElementById("nn").value;
    let age=parseInt(document.getElementById("agg").value);
    let home=document.getElementById("hometown").value;
    let res="Welcome: "+name+"<br>"+"Age: "+age+"<br>"+"Hometown: "+"<a href=\"https://google.com/search?q=" + home + "\">Link</a>";

    document.getElementById("result").innerHTML=res;
}

//Q.18
function changeimg(){
    document.getElementById("roll").src="kid.png";
}
function resetimg(){
    document.getElementById("roll").src="luff.png";
}//Harsh VM