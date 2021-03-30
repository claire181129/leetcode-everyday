#include <iostream>
#include <string>
#include <vector>

std::string sort(std::string str)
{
    auto size = str.size();
    std::vector<char> output(size,-1);
    std::string letters;
    for(int i=0;i<size;i++)
    {//97-122, 65-90
        if((str[i]>=65 && str[i]<=90)||(str[i]>=97 && str[i]<=122))
        {//uppercase
            letters.append(1,str[i]);
        }
        else
        {
            output[i] = str[i];
        }
    }
    int i=0;
    auto letters_size = letters.size();
    while(i<letters_size)
    {
        char letter = letters[i];
        if(letter>=97)
            letter -= 32;
        //find smallest letter, range[i,end]
        for(int j = i+1;j<letters_size;j++)
        {
            if(letters[j]>=97)
                if(letter>(letters[j]-32))
                {
                    #ifdef DEBUG
                        std::cout<<"\tsmaller lowercase:"<<letters[j]<<" letter:"<<letter<<std::endl;
                    #endif
                    letter = letters[j]-32;
                }
                else
                {
                    #ifdef DEBUG
                        std::cout<<"\tlowercase:"<<letters[j]<<">= letter:"<<letter<<std::endl;
                    #endif
                }
            else
                if(letter>letters[j])
                {
                    #ifdef DEBUG
                        std::cout<<"\tsmaller uppercase:"<<letters[j]<<" letter:"<<letter<<std::endl;
                    #endif
                    letter = letters[j];
                }
                else
                {
                    #ifdef DEBUG
                        std::cout<<"\tuppercase:"<<letters[j]<<">= letter:"<<letter<<std::endl;
                    #endif
                }
        }
        #ifdef DEBUG
            std::cout<<"\tsmallest letter:"<<std::string(1,letter)<<" i:"<<i<<std::endl;
        #endif
        //move all smallest letter to position i
        if(letters[i] == letter || letters[i] == letter+32)
            i++;
        for(int j=i;j<letters_size;j++)
        {
            if((letters[j] == letter) || (letters[j] == letter+32))
            {
                #ifdef DEBUG
                    std::cout<<"\tfound letter j:"<<j<<" letter:"<<std::string(1,letters[j])<<std::endl;
                #endif
                char temp = letters[j];
                letters.erase(j,1);
                letters.insert(i,1,temp);
                i++;
            }
        }
        #ifdef DEBUG
            std::cout<<"\ti:"<<i<<std::endl;
            std::cout<<"\tletters:"<<letters<<std::endl;
        #endif
    }
    #ifdef DEBUG
        std::cout<<"\tletters:"<<letters<<std::endl;
    #endif
    int index = 0;
    for(int i=0;i<size;i++)
    {
        if(output[i] == -1)
        {
            output[i] = letters[index];
            index++;
        }
    }
    std::string result(output.begin(),output.end());
    return result;
}
int main()
{
    std::string str;
    while(std::getline(std::cin,str))
    {
        std::cout<<sort(str)<<std::endl;
    }
    return 0;
}
/*
case:
A Famous Saying: Much Ado About Nothing (2012/8).
Type
BabA
By?e
anwser:
A aaAAbc dFgghh: iimM nNn oooos Sttuuuy (2012/8).
A aaAAbc dFgghh: iimM nNn oooos Sttuuuy (2012/8).
epTy
aABb
Be?y

trace:
AaaAA Fmous Sying: Much do bout Nothing
Type
i = 0, T
    j = 1, y
    j = 2, p, pTye
    j = 3, e, epTy
i = 1, p

Oh Famous Saying: Much Ado About Nothing (2012/8).
OhFamousSayingMuchAdoAboutNothing
aaAAOhFmousSyingMuchdoboutNothing

#$A^!#ab&~#CccCCCcDdef&Fff%g@(hIkl@LM^mmOPP((p$P-Rs&T-t$t%Uuv)wxYy@y-yZ
a-&aA@aaABbbB$%&bBBB%bCCC%CC(CD$d!!dDD*DDdDDddeE!EE-$F~%@fFF^f$g-G@GG@Gg#g*h$HhhH&Hh(&hhH^H%III#(-!iIiII)j%JJjJJ+J&%jJJJkkK!(%k-)$KKl-!)L-L~lLL##+lmM^MMMmNn$nN&nn@n@n^*+nnNooO%Oo(O$oo^%oO~!O*%&@!ppppPPPppPpQq(!!(QR#Rr%rrrR(RRR(*S&sSs&S~-ssst^)$!~ttu*uu%+uuVVVvV)Vvww+w$wWwwxxX%xxXx%yYYyY%yZ#%#+(ZZZZ(zZ^Z#&zZ

#$A^!#ab&~#CccCCCcDdef&Fff%g@(hklL@Mm^mPPpP((s$T-tt&U-u$v%wxY)yyyZ@O-IR
a-&aA@aaABbbB$%&bBBB%bDdd%DD(DD$d!!DDd*deEEEFfFF!fg-$G~%@GGG^g$g-h@Hh@hH#H*h$hhHH&II(&IiI^i%IIj#(-!JJjJJ)J%jJJJk+k&%KkKKlLL!(%l-)$LLl-!)m-M~MMM##+mNn^nNnnnn$nn&No@o@O^*+OoOooo%OO(p$pp^%pP~!P*%&@!PppPpQqQRRrrr(!!(rR#RR%RSsS(sSs(*s&stt&t~-uuuu^)$!~uVV*Vv%+VVvwwww)Wwwx+x$XxxXxyY%YyYy%ZZZZZ%zZ#%#+(ZzZC(CC^C#&CC

i:18
	letters:AabCccCCCcDdefFffgYPUyTtZhslyMmuOILmyvwxPtRpkP
	smallest letter:H i:18
	found letter j:25 letter:h
i:19
	letters:AabCccCCCcDdefFffghYPUyTtZslyMmuOILmyvwxPtRpkP
	smallest letter:K i:19
	found letter j:44 letter:k
i:20
	letters:AabCccCCCcDdefFffghkYPUyTtZslyMmuOILmyvwxPtRpP
	smallest letter:L i:20
	found letter j:28 letter:l
	found letter j:35 letter:L
AabCccCCCcDdefFffgYPUyTtZhslyMmuOILmyvwxPtRpkP
*/