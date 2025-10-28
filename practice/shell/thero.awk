    BEGIN { FS=":"; print "Theropod dinosaurs" }
    {
        if ($2 ~ "theropod") { print "\t" $1; n++ }
    }
    END { print n " theropods found" }
