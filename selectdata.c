#include<stdio.h>
#include<mysql.h>


int main(){
    //创建mysql描述符
    MYSQL* mysql_fd = mysql_init(NULL);
    //连接数据库
    if(mysql_real_connect(mysql_fd,"127.0.0.1","root","","bit",3306,NULL,0) ==NULL){
        printf("connect failed\n");
        return 1;
    }
    //连接成功
    char buf[1024]= {};
    sprintf(buf,"select * from bit2");
    mysql_query(mysql_fd,buf);
    MYSQL_RES *res = mysql_store_result(mysql_fd);
    int row = mysql_num_rows(res);
    int col = mysql_num_fields(res);
    MYSQL_FIELD * field = mysql_fetch_field(res);
    int i = 0;
    for(;i<col;i++){
        printf("%s\t",field[i].name);
    }
    printf("\n");
    printf("<table border=\"1\">");
    for(i = 0;i<row;++i){
        int j = 0;
        MYSQL_ROW rowdata = mysql_fetch_row(res);
        printf("<tr>");
        for(;j<col;++j){
            printf("<td>%s<td>",rowdata[j]);
        }
        printf("</tr>");
    }
    printf("</table>");
    mysql_close(mysql_fd);
    printf("OK!");
    return 0;
}
