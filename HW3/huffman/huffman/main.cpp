1:  #include <stdio.h>
2:	#include <stdlib.h>
3:	#include <string.h>
4:
5:	struct node{
    6:		int value;
    7:		int data;
    8:		struct node *next, *left, *right;
    9:	};
10:
11:	typedef struct node Node;
12:
13:	struct tree{
    14:		int num;
    15:		Node *start;
    16:	}*Tree;
17:
18:	int *Map;
19:
20:	void initial_node(int *freq){
    21:		Tree = (struct tree*) malloc(sizeof(struct tree));
    22:		Tree->num = 0;
    23:		Node *Ptr;
    24:
    25:		int datamin, fmin = 1, dmin;
    26:		do{
        27:			/////select min/////
        28:			dmin = 1000;
        29:			for (int i = 0; i < 256; i++){
            30:				int tmp = freq[i] - fmin;
            31:				if ((tmp <= dmin) && (tmp >= 0)){
                32:					dmin = tmp;
                33:					datamin = i;
                34:					if (tmp == 0)
                    35:						break;
                36:				}
            37:			}
        38:
        39:			fmin = freq[datamin];
        40:			freq[datamin] = 0;
        41:
        42:			if (dmin == 1000)
            43:				break;
        44:
        45:			////node to node////
        46:			Node *node;
        47:			node = (Node*) malloc(sizeof(Node));
        48:			node->left = NULL;
        49:			node->right= NULL;
        50:			node->value= fmin;
        51:			node->data = datamin;
        52:			if (Tree->num == 0)
            53:				Tree->start = node;
        54:			else
            55:				Ptr->next = node;
        56:			Tree->num++;
        57:			Ptr = node;
        58:
        59:		}while(1);
    60:
    61:		Ptr->next = NULL;
    62:	}
63:
64:	void huffman_tree(){
    65:		while(Tree->num != 1){
        66:			Node *NewNode, *Ptr;
        67:			NewNode = (Node*) malloc(sizeof (Node));
        68:
        69:			////create new node
        70:			Ptr = Tree->start;
        71:			NewNode->left = Ptr;
        72:			NewNode->right= Ptr->next;
        73:			NewNode->data = -1;
        74:			NewNode->value= Ptr->value + Ptr->next->value;
        75:			NewNode->next = NULL;
        76:
        77:			////delete old next////
        78:			Tree->start = Ptr->next->next;
        79:			Ptr->next->next = NULL;
        80:			Tree->num--;
        81:
        82:			////sort///
        83:			if (Tree->num == 1){
            84:				Tree->start = NewNode;
            85:				break;
            86:			}
        87:
        88:			Ptr = Tree->start;
        89:			if (Ptr->value >= NewNode->value){
            90:				NewNode->next = Ptr;
            91:				Tree->start   = NewNode;
            92:			}
        93:			else{
            94:				while(1){
                95:					if (Ptr->next == NULL){
                    96:						Ptr->next = NewNode;
                    97:						NewNode->next = NULL;
                    98:						break;
                    99:					}
                100:
                101:					if ((Ptr->value < NewNode->value) && (Ptr->next->value >= NewNode->value)){
                    102:						NewNode->next = Ptr->next;
                    103:						Ptr->next     = NewNode;
                    104:						break;
                    105:					}
                106:					Ptr = Ptr->next;
                107:				}
            108:			}
        109:		}
    110:	}
111:
112:	void Tree_Left(Node* node, int code);
113:
114:	void Tree_Right(Node* node, int code){
    115:		if (node == NULL)
        116:			return;
    117:
    118:		code = code*2 + 1;
    119:		Tree_Right(node->right, code);
    120:		if (node->data != -1)
        121:			Map[node->data] = code;
    122:		Tree_Left(node->left, code);
    123:	}
124:
125:	void Tree_Left(Node* node, int code){
    126:		if (node == NULL)
        127:			return;
    128:
    129:		code = code* 2;
    130:		Tree_Right(node->right, code);
    131:		if (node->data != -1)
        132:			Map[node->data] = code;
    133:		Tree_Left(node->left, code);
    134:	}
135:
136:
137:	void codelist(){
    138:		Map = (int*) malloc(256* sizeof(int));
    139:		for (int i = 0; i < 256; i++)
        140:			Map[i] = 0;
    141:
    142:		int code = 1;
    143:		Tree_Right(Tree->start->right, code);
    144:		Tree_Left(Tree->start->left, code);
    145:	}
146:
147:	void deleteNode(Node *pt){
    148:		if (pt == NULL)
        149:			return;
    150:
    151:		deleteNode(pt->right);
    152:		deleteNode(pt->left);
    153:		free(pt);
    154:
    155:		return;
    156:	}
157:
158:
159:	int main(){
    160:		int *freq;
    161:		freq = (int*) malloc(256* sizeof(int));
    162:		for (int i = 0; i < 256; i++)
        163:			freq[i] = 0;
    164:
    165:		///////count///////
    166:		FILE *fp = fopen("input.txt", "r");
    167:		int loc;
    168:
    169:		while((loc = (int)fgetc(fp)) != EOF)
        170:			freq[loc] ++;
    171:
    172:		fclose(fp);
    173:
    174:		//////initial node/////
    175:		initial_node(freq); //sort and node
    176:
    177:		/////huffman tree////
    178:	   	huffman_tree();
    179:
    180:		////letter map code////
    181:		codelist();
    182:
    183:		FILE *input = fopen("input.txt", "r");
    184:		FILE *output= fopen("text.txt", "w");
    185:
    186:		int max, tmp;
    187:		while((loc = (int)fgetc(input)) != EOF){
        188:			max = 1;
        189:			while(1){
            190:				if (max > Map[loc])
                191:					break;
            192:				max = max* 2;
            193:			}
        194:			tmp = Map[loc] - max/2;
        195:			for (int i = max/4; i > 0; i = i/2){
            196:				if (tmp >= i){
                197:					fputs("1", output);
                198:					tmp = tmp - i;
                199:				}
            200:				else
                201:					fputs("0", output);
            202:			}
        203:		}
    204:
    205:
    206:		fclose(input);
    207:		fclose(output);
    208:	
    209:		input = fopen("text.txt", "r");
    210:		output= fopen("output.txt", "w");
    211:		char token;
    212:		Node *pt;
    213:		pt = Tree->start;
    214:		while((token = fgetc(input)) != EOF){
        215:			if (token == '1')
            216:				pt = pt->right;
        217:			else
            218:				pt = pt->left;
        219:	
        220:			if (pt->right == NULL && pt->left == NULL){
            221:				fprintf(output, "%c", (char)(pt->data));	
            222:				pt = Tree->start;
            223:			}
        224:			
        225:		}
    226:		fclose(input);
    227:		fclose(output);
    228:	;
    229:		free(freq);
    230:		free(Map);
    231:		deleteNode(Tree->start);
    232:		free(Tree);	
    233:		return 0;
    234:	}