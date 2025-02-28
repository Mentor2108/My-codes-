library(tidyverse)
library(readxl)
library(psych)
library(rstatix)
library(knitr)
library(svglite)
library(QuantPsyc)
library(lubridate)
library(reshape2)
library(car)
library(broom)
library(estimatr)
library(lmtest)
library(relaimpo)
library(gmodels)
library(janitor)

# read file "data with labels.xlsx"
dat1 = read_excel(file.choose(), skip = 1)

#
names(dat1)
dim(dat1)
unique(dat1$gen)

for (colName in colnames(dat1)) {
  message(cat("current column: ",  colName, "\n"))
  if (substring(colName, 1, 1) == 'x') {
    # current column in character list
    currCharacterRow = sapply(dat1[[colName]], function(x)
      paste(tail(x, 3), collapse = " "))
    
    for (categoryName in c('gen', 'age', 'edu', 'inc', 'exp')) {
      # frequency distribution
      freq_dist = table(dat1[[colName]])
      message("Frequency Distribution:")
      print(freq_dist)
      
      freq_prob_dist = prop.table(freq_dist)
      message("Frequency Probability Distribution:")
      print(freq_prob_dist)
      
      # 2nd way frequency table
      freq_dist_with_prob = tabyl(dat1, all_of(colName)) %>%
        adorn_pct_formatting(digits = 1)
      message("Frequency Distribution with Probability:")
      print(freq_dist_with_prob)
      
      freq_dist_category_wise = tabyl(dat1, all_of(categoryName)) %>%
        adorn_pct_formatting(digits = 1)
      message("Frequency Distribution on basis of category:")
      print(freq_dist_category_wise)
      
      #bar plot of column for each category
      graph_of_count_category_basis = ggplot(dat1, aes(x = !!rlang::sym(colName))) +
        geom_bar() +
        facet_wrap(categoryName) +
        theme(panel.background = element_blank())
      #print(graph_of_count_category_basis)
      graphFileName =
        paste("column_",
              colName,
              "_category_",
              categoryName,
              ".svg",
              sep = "")
      ggsave(
        filename = file.path("figs", graphFileName),
        plot = graph_of_count_category_basis,
        width = 10,
        height = 8
      )
      
      curr_formula <-
        as.formula(paste(as.character(colName), "~", as.character(categoryName)))
      
      # summary or descriptive statistics on basis of category
      if (typeof(head(dat1[[colName]], 1)) == 'double') {
        summary_category_basis = dat1 %>%
          group_by_at(categoryName) %>%
          rstatix::select(categoryName, colName) %>%
          get_summary_stats(type = "common")
        message("Summary of data on basis of categories:")
        print(summary_category_basis)
        
        # t test
        res_test = dat1 %>%
          t_test(formula = curr_formula,
                 alternative = "two.sided")
        message("T test result:")
        print(res_test)
        
        # anova
        res_anova = dat1 %>%
          welch_anova_test(curr_formula)
        message(cat(
          "anova test result for column",
          colName,
          "and category",
          categoryName
        ))
        print(res_anova)
      }
      
      message("cross table data result:")
      cross_table_data = CrossTable(
        dat1[[colName]],
        dat1[[categoryName]],
        digits = 2,
        prop.r = T,
        prop.c = F,
        prop.t = F,
        format = "SPSS",
        prop.chisq = F
      )
      
      # chi square test
      message("cross table with Chi Square Test:")
      cross_table_chisq = CrossTable(
        dat1[[colName]],
        dat1[[categoryName]],
        digits = 2,
        expected = T,
        prop.r = F,
        prop.c = F,
        prop.t = F,
        format = "SPSS",
        prop.chisq = F,
        chisq = T
      )
    }
    
    # bar plot
    graph_of_count = ggplot(dat1, aes(x = !!rlang::sym(colName)))  + ggtitle("Bar graph of counts") + geom_bar() +
      theme(panel.background = element_blank())
    #print(graph_of_count)
    graphFileName =
      paste("column_",
            colName,
            ".svg",
            sep = "")
    ggsave(
      filename = file.path("figs", graphFileName),
      plot = graph_of_count,
      width = 10,
      height = 8
    )
    
    # summary or descriptive statistics
    
    message("test")
    if (typeof(head(dat1[[colName]], 1)) == 'double') {
      message("bro")
      summary = dat1 %>%
        rstatix::select(all_of(colName)) %>%
        get_summary_stats(type = "common")
      message("Summary of data:")
      print(summary)
    }
  }
}

#chisq_table = tabyl(dat1, x1, gen)
#chisq_table %>% adorn_percentages("col") %>% adorn_pct_formatting(digits = 1)
#print(chisq_table)
#chisq.test(chisq_table)
