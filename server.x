struct X_vec {
	int n;
	int X<>;
};

struct product {
	int n;
    int X<>;
    int Y<>;
};

struct mean {
	int n;
    int X<>;
    int Y<>;
};

struct r_product {
	int n;
	float r;
    int X<>;
    int Y<>;
};

struct mean_table{
    float XY<2>;
};

struct product_table{
    float rXY<>;
};


program CAL_PROG {
		version ADD_VERS {
			float mangi(X_vec) = 1;
            int X_Y(product) = 2;
            mean_table cal_mean(mean) = 3;
            product_table r_XY(r_product) = 4;
	} = 1;
} = 0x23451111;
