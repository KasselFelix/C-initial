int nb_mots(char *phrase){
        int i,nb=0;
        for(i=0;*(phrase+i)!='\0';i++){
            if(*(phrase+i)!=' ' && (*(phrase+i+1)==' ' || *(phrase+i+1)=='\0') ){
                nb++;
            }
        }
        return nb;
}

int main(){
    char *phrase="  un deux trois quatre ";
    printf("%d\n",nb_mots(phrase));
    return 0;
}
