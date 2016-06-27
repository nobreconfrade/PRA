# William Pereira
require 'open-uri'
require 'ferret'
include Ferret

puts ("Digite a URL do site:")
url = gets
fh = open(url)
html = fh.read
puts html
puts ("Digite o nome do arquivo de saida:")
txt = gets
open(txt,'w') { |f|
  f.puts html
}
puts("Arquivo gerado com sucesso, nome: "+txt)

index << {:title => txt,:content => html}  