#include "engine.h"
#include "util.h"
#include <stdio.h>

bool run_statements(struct context *ctx, const char **input, struct error *err)
{
    // Skip the whitespace at the beginning of input
    skip_whitespace(input);

    // Check if we are at a valid end of a sequence of statements if we are do nothing
    if (**input == '\0' || **input == '}')
        return true;

    // Otherwise, run a single statement and then the rest of the statements
    return run_statement(ctx, input, err) && run_statements(ctx, input, err);
}

bool run_statement(struct context *ctx, const char **input, struct error *err) 
{
    if (**input == '\0')
    {
        err->pos = *input;
        err->desc = "expected a input";
        return false;
    }

    int data, c1 = 0, *c2 = &ctx->x;
    bool cond;

    // Handle "ENQ" statement.
    if (starts_with(*input, "ENQ("))
    {
        *input += 4; // Skip "ENQ("
        skip_whitespace(input);
        eval_expression(ctx, input, err, &data);
        enqueue(&ctx->q, data);
    }

    // Handle "ASSERT" statement.
    if (starts_with(*input, "ASSERT("))
    {
        *input += 7; // Skip "ASSERT("
        skip_whitespace(input);
        eval_condition(ctx, input, err, &cond);
        if (cond) // If the condition is true, return true
        {
            return true;
        }
        else
        {
            err->pos = *input;
            err->desc = "assertion failed";
            return false;
        }
    }

    // Handle variable assignments (x and y).
    if (starts_with(*input, "x = "))
    {
        *input += 4; // Skip "x = "
        skip_whitespace(input);
        eval_expression(ctx, input, err, &data);
        ctx->x = data; // Assign the value to x
    }
    else if (starts_with(*input, "y = "))
    {
        *input += 4; // Skip "y = "
        skip_whitespace(input);
        eval_expression(ctx, input, err, &data);
        ctx->y = data; // Assign the value to y
    }

    // Handle loops (WHILE statement).
    if (starts_with(*input, "WHILE ("))
    {
        *input += 7; // Skip "WHILE ("
        skip_whitespace(input);
        eval_expression(ctx, input, err, &c1);
        if (**input == '<')
        {
            (*input)++;
        }
        skip_whitespace(input);
        eval_expression(ctx, input, err, c2);
        *input += 3; // Skip ") {"
        char *loop = *input; // Save the current position
        while (c1 < *c2)
        {
            *input = loop; // Reset the position
            run_statements(ctx, input, err);
        }
        (*input)++; // Skip "}"
    }

    if (**input == '}') // If we are at the end of a block, return true
        return true;
    while (**input == ';' || **input == ')')
        (*input)++;

    return true;
}

bool eval_expression(struct context *ctx, const char **input, struct error *err, int *out) // Evaluate an expression
{
    if (**input == '\0')
    {
        err->pos = *input;
        err->desc = "expected expression";
        return false;
    }

    int value, count = 0; // Count is used to check if we have parsed an integer
    if (**input == 'x')
    {
        *out = ctx->x;
    }
    else if (**input == 'y')
    {
        *out = ctx->y;
    }

    if (**input >= '0' && **input <= '9') // If the current character is a number between 0-9, parse as integer
    {
        parse_integer(input, err, out);
        count = 1;
    }

    if (**input == '-') // Handle negative integers
    {
        (*input)++;
        *out = (**input - 48) * (-1); // Convert the character to an integer and multiply by -1
    }

    if (starts_with(*input, "DEQ")) // Handle "DEQ" to dequeue from the queue
    {
        *input += 3;
        dequeue(&ctx->q, out);
    }

    if (!count) // If we have not parsed an integer, return true
        (*input)++;

    // Handle addition "+"" between expressions
    if (**input == ';')
        return true;
    else
    {
        skip_whitespace(input);
        if (**input == '+')
            (*input)++;
        else
            return true;
        skip_whitespace(input);
        eval_expression(ctx, input, err, &value);
        *out += value; // Add the value to the current value
    }

    return true;
}

bool eval_condition(struct context *ctx, const char **input, struct error *err, bool *out) // Evaluate a condition
{
    if (**input == '\0')
    {
        err->pos = *input;
        err->desc = "expected condition";
        return false;
    }

    int val1, val2;
    bool cond;

    // Handle "EMPTY" condition.
    if (starts_with(*input, "EMPTY"))
    {
        *input += 5; // Skip "EMPTY"
        if (queue_empty(&ctx->q))
            *out = true;
        else
            *out = false;
    }

    if (**input != '!')
        eval_expression(ctx, input, err, &val1);
    skip_whitespace(input);

    // Handle == and < conditions
    if (**input == '=')
    {
        // Handle == condition
        (*input)++;
        skip_whitespace(input);
        eval_expression(ctx, input, err, &val2);
        if (val1 == val2)
            *out = true;
        else
            *out = false;
    }
    else if (**input == '<')
    {
        // Handle < condition
        (*input)++;
        skip_whitespace(input);
        eval_expression(ctx, input, err, &val2);
        if (val1 < val2)
            *out = true;
        else
            *out = false;
    }

    // Handle ! condition.
    if (**input == '!')
    {
        (*input)++;
        eval_condition(ctx, input, err, &cond);
        if (!cond)
            *out = true;
        else
            *out = false;
    }

    return true;
}

bool parse_integer(const char **input, struct error *err, int *out)
{
    // Try to parse an integer at the current position, incrementing *input to after the integer
    const char *before = *input;
    int result = (int)strtol(before, (char **)input, 10); // Convert the string to an integer

    // If no characters were used, then the input was invalid
    if (*input == before)
    {
        err->pos = before;
        err->desc = "expected integer";
        return false;
    }
    else
    {
        *out = result;
        return true;
    }
}