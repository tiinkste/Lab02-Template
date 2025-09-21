#include <stdio.h>

// Amount of each product currently in stock
float apples_in_stock = 7.2f;
float carrots_in_stock = 4.1f;
int chips_in_stock = 9;
int candy_in_stock = 3;

// Prices of each product
float apples_price = 5.99f;
float carrots_price = 3.99f;
float chips_price = 2.99f;
float candy_price = 1.5f;


// Prompts the user to input the amount of each product they would like to buy
int prompt_purchase(float *apples_p, float *carrots_p, int *chips_p, int *candy_p){
	
	// Ask how many apples the user wants to buy
	printf("%-11s(%-6.2fkg) : ", "Apples", apples_in_stock);
	
	// If user inputs bad value, scanf fails - return 1
	if (scanf("%f", apples_p) != 1){
		return 1; } 
	
	// If user inputs value greater than current stock or less than zero - return 1
	if (*apples_p < 0 || *apples_p > apples_in_stock){
		return 1; }
	
	// Clear the input buffer
	while (getchar() != '\n'); 
	
	
	// Repeat with carrots, chips, candy
	printf("%-11s(%-6.2fkg) : ", "Carrots", carrots_in_stock);
	if (scanf("%f", carrots_p) != 1){
		return 1; } 
	if (*carrots_p < 0 || *carrots_p > carrots_in_stock){
		return 1; }
	while (getchar() != '\n');
	
	printf("%-11s(%-3dunits) : ", "Chips", chips_in_stock);
	if (scanf("%d", chips_p) != 1){
		return 1; } 
	if (*chips_p < 0 || *chips_p > chips_in_stock){
		return 1; }
	while (getchar() != '\n'); 
	
	printf("%-11s(%-3dunits) : ", "Candy", candy_in_stock);
	if (scanf("%d", candy_p) != 1){
		return 1; } 
	if (*candy_p < 0 || *candy_p > candy_in_stock){
		return 1; }
	while (getchar() != '\n'); 
	
	
	// All inputs valid - return 0
	return 0;
}


// Main function
int main(int argc, char* argv[]){
	
	// The amount of each product the user wants to buy
	float apples_wanted, carrots_wanted;
	int chips_wanted, candy_wanted;
	
	// Pointers for the previously declared variables
	float *apples_p = &apples_wanted;
	float *carrots_p = &carrots_wanted;
	int *chips_p = &chips_wanted;
	int *candy_p = &candy_wanted;
	
	// For testing input validity
	int valid_input;
	
	// Contains the amount discounted from the final order
	float discount = 0.0f;
	
	
	// Prompt the user for input & validate it
	valid_input	= prompt_purchase(apples_p, carrots_p, chips_p, candy_p);
	
	if(valid_input){
		return 1; }
	if(apples_wanted == 0 && chips_wanted == 0 && carrots_wanted == 0 && candy_wanted == 0){
		return 0; }
	
	// Check if "For every 2 bags of chips purchased, get 1 candy 50% off!" promotion applies
	if (chips_wanted >= 2 && candy_wanted >= 1){
		int temp_chips = chips_wanted;
		int temp_candy = candy_wanted;
		
		// For every 2 chips & 1 candy, apply the discount again
		while(temp_chips >= 2 && temp_candy >= 1){
			discount += candy_price/2;
			temp_chips -= 2;
			temp_candy -= 1;
		}	
	}
	
	
	// Display the table
	printf("\n");
	printf("-------------------------------------------------------------------\n| %-9s| %-13s| %-11s| %-12s| %-11s|\n", "Item", "Quantity", "Cost", "Discount", "Total");
	
	if (apples_wanted > 0){
		printf("| %-9s| %-9.2f kg | $%9.2f | -$%9.2f | $%9.2f |\n", "Apples", apples_wanted, (apples_price*apples_wanted), 0.0f, (apples_price*apples_wanted)); }
	
	if (carrots_wanted > 0){
		printf("| %-9s| %-9.2f kg | $%9.2f | -$%9.2f | $%9.2f |\n", "Carrots", carrots_wanted, (carrots_price*carrots_wanted), 0.0f, (carrots_price*carrots_wanted)); }
	
	if (chips_wanted > 0){
		printf("| %-9s| %-12d | $%9.2f | -$%9.2f | $%9.2f |\n", "Chips", chips_wanted, (chips_price*chips_wanted), 0.0f, (chips_price*chips_wanted)); }
	
	if (candy_wanted > 0){
		printf("| %-9s| %-12d | $%9.2f | -$%9.2f | $%9.2f |\n", "Candy", candy_wanted, (candy_price*candy_wanted), discount, (candy_price*candy_wanted) - discount); }
	
	printf("-------------------------------------------------------------------\n");
	printf("\n");
	
	
	// Determine final cost for checkout
	
	// The total cost of all products in the user's cart
	float total_cost = (apples_price*apples_wanted) + (carrots_price*carrots_wanted) + (chips_price*chips_wanted) + ((candy_price*candy_wanted) - discount);
	discount = 0.0f;
	
	// Check if "Buying at least 1kg / 1unit of every of the four items" promotion applies
	if (chips_wanted > 0 && candy_wanted > 0 && apples_wanted > 0 && carrots_wanted > 0){
		discount += total_cost/10; }
	
	// Use the long form if there are discounts to apply
	if (discount > 0){
		printf("%-16s: $%.2f - $%.2f = $%.2f\n", "Subtotal", total_cost, discount, (total_cost - discount));
		total_cost -= discount;
	} else {
		printf("%-16s: $%.2f\n", "Subtotal", total_cost); }
	
	// Tax for goods in Alberta is only GST - 5%!
	float tax = total_cost/20;
	
	// Print receipt
	printf("%-16s: $%.2f\n", "Tax (5%)", tax);
	printf("----------------------------------------------------\n");
	printf("%-16s: $%.2f\n", "Total", total_cost + tax);
	
	
	return 0;
}
