# A Study of Hominins’ Mitochondrial DNA

## Introduction
Denisovans are an archaic human, said to be a sister group to Neanderthals. They are believed to have split from Neanderthals, 390,000 years ago (Slon et al., 2018). Current theory speculates that humans displaced populations of archaic humans in Eurasia 40,000 years ago (Slon et al., 2018). There is evidence of breeding between archaic humans and certain populations of homo sapiens (Slon et al., 2018). Analysis was conducted between various populations of modern humans to determine introgression, notably between Papua New Guineans and Denisovans in autosomal DNA.

Ancient DNA (aDNA) is prone to contamination and degradation (Pääbo et al., 2004). Often, sequences are fragmented and short in length, in part due to hydrolytic cleavage in the phosphodiester bonds of the DNA strand (Willerslev & Cooper, 2005). Another consideration is that DNA is damaged through different naturally occurring reactions (Willerslev & Cooper, 2005).  Enzymatic processes in the cell repairs DNA - however - post-mortem, such machinery is no longer available (Willerslev & Cooper, 2005). A consequence of using aDNA is the increase in contamination (Pääbo et al., 2004). One such example is during the use of PCR to amplify aDNA, the primers used are also compatible with modern human DNA (Willerslev & Cooper, 2005). A speck of dust from a human technician could theoretically contain more mtDNA sequences than an entire aDNA sample. Cloning and sequencing would occur with the modern sequence rather than the ancient sequence (Pääbo et al., 2004). Enzymatic processes are used in the lab to correct for any mistakes in the aDNA after degradation (Pääbo et al., 2004). Clean labs are also routinely employed to limit contamination from modern DNA.

The mitochondria is an organelle present in most eukaryotes that contains its own DNA (Ladoukakis & Zouros, 2017). It is believed to have regressed from an alpha proteobacteria engulfed by an ancestor of eukarya and archaea (Williams et al., 2007). Genetic information exchange occurred between the mitochondria and host cell, reducing the size of the mitochondrial DNA (mtDNA), causing it to become dependent on the host cell (Sato & Sato, 2013). Unlike genomic DNA (gDNA), mtDNA is circular. There exists a region in mtDNA that expresses a higher rate of mutation compared to the rest of the mtDNA (Gupta & Bhardwaj, 2013). It is known as either the D-loop, or the control region. In general, mtDNA has a higher rate of mutation than gDNA which makes it ideal for identifying single nucleotide polymorphisms (SNPs) for phylogenetic analysis (Gupta & Bhardwaj, 2013). Other considerations are that mtDNA is much smaller than gDNA, around ~17 kbp vs. ~300 gbp in humans. Mitochondria are typically inherited from mothers, although leakage is possible (Sato & Sato, 2013). Homoplasmy, in the context of mtDNA, refers to mitochondria that are identical and are from a single parent. Heteroplasmy, which is often associated with diseases, occurs when there is paternal leakage and two sets of mitochondria exist (Sato & Sato, 2013).

Using mtDNA is not infallible. There are a number of issues that arise when working with a small set of DNA. The first is back substitution, which means that a SNP may revert back to the ancestral or previous base due to high selective pressure (Gupta & Bhardwaj, 2013). There is also parallel substitution in which two separate organisms mutate to achieve the same SNP independent of one another (Gupta & Bhardwaj, 2013). This is contributed by the higher rate of mutation of the mtDNA, as well as the control region which is not under as much selective pressure as the rest of the mitochondrial genome (Gupta & Bhardwaj, 2013).
Conserved variant regions in a population are haplotypes (Gabriel, 2002). These can be determined by observing the variant and the ancestral segment (Gabriel, 2002). Haplotypes are conserved between populations (Gabriel, 2002). It is possible then to determine given a haplogroup which is a set of haplotypes with a shared ancestor (Gabriel, 2002). 

There is evidence showing that modern humans have interbred with Neanderthals - non-African human beings inherit 2–3% Neanderthal genome. Although conserved ancient Neanderthal genome detected in human beings is of a rather small size, it is easily recognizable due to its uniqueness (Johnson et al., 2014). However, to date, there is no evidence of introgression between Denisovan mtDNA and humans (Sharbrough et al., 2017). It is possible to determine - through identifying conserved regions of SNPs in the mtDNA of modern humans and Denisovans - if breeding did occur between these groups (Sharbrough et al., 2017). This paper analyses the variants in the mtDNA of populations of modern humans and, Denisovans. 

## Objectives 
The objectives of this paper are: to investigate the phylogenetic history of the mtDNA between Neanderthals, Denisovans and, homo sapiens; to identify the similarities and differences between the mtDNA of Denisovans and homo sapiens; to analyze in which population of homo sapiens most resemble Denisovans.

## Methods
### Data Acquisition:
The data used in this study was obtained from the 3rd Phase of the 1000 Genomes Project (Gibbs et al., 2015). This includes a variety of human genomes from a wide set of geographical locations and backgrounds. The data was provided in both FASTA and VCF formats. Regarding the VCF file, all of the mtDNA sequences were aligned to the Revised Cambridge Reference Sequence (rCRS, NCBI accession NC0012920.1) (Andrews et al., 1999). The ancient human mtDNA data used in this study consists of 6 Neanderthal mitochondrial genomes (NCBI accessions FM865407 - FM865411, NC011137), 4 Denisovan mitochondrial genomes - the raw reads for Denisovans 2, 3, 4, and 8  (NCBI accessions KX663333, NC013993, FR695060, KT780370). However, the raw reads for Denisova 2 was excluded due to its poor quality. The raw reads for the Denisovan mtDNA were uploaded by the Max Planck Institute for Anthropological Science onto the EMBL-EBI database, in the fastq format (Sawyer et al., 2015).

To process the data, each of the raw Denisovan reads were aligned to the rCRS using the BWA tool (Li & Durbin 2010). This produced a SAM file that could then be converted into a VCF, using samtools (Li et al., 2009). After repeating for each of the Denisovan raw reads, the VCF files were merged to the 1000 Genomes Project VCF. All rows in the VCF file were filtered to remove any non-consensus variants.The merged VCF was parsed using a Python library called Pandas (Wes, 2010), using a custom script. This allowed for easy extraction of haplotype sequences and manipulation of the data.

### Phylogenetic Analysis:
For the multiple sequence alignment, we used Seaview to process the entire mtDNA sequences (Galtier et al., 1996). We used the MUSCLE algorithm for our alignment. The data that we analyzed consisted of one mitochondrial sequence from each population that appeared in the 1000 Genomes Project. The populations found in the 1000 Genomes Project include British, Finnish, Luhya, Mende, Gujarati, East Asian and others. Additionally, six Neanderthal mitochondrial sequences and four Denisovan mitochondrial sequences were included. A sequence from chimpanzee was added to act as an outgroup. The phylogenetic tree was generated from the multiple sequence alignment, using the Bio-NJ method with a bootstrap number of 100.

### Clustering
In order to use clustering algorithms on the data, a distance matrix was computed from a haplotype sequence alignment. This was done in R using the Ape package (Paradis & Schliep, (2018). Afterwards, the distance matrix generated in R was transferred back into Pandas. Scikit-Learn - a popular Python package for machine learning - was used to execute the clustering algorithms, on the distance matrix (Pedregosa, 2011). The advantage of using Scikit-Learn over R, is that Scikit-Learn is a multi-core package which allows it to run clustering algorithms faster. In addition, the sequences we used were the same as those for generating the phylogenetic tree.

Two algorithms were used for clustering, Principal Component Analysis (PCA) and t-distributed Stochastic Neighbour Embedding (t-SNE). PCA uses eigenvalue decomposition to project high dimensional data into a lower dimensional space. This method produces a deterministic result, meaning that the result will remain the same every time it is run. To confirm the reproducibility of our results, the same PCA analysis was performed using R, the resulting plots were identical. t-SNE uses maximum likelihood to group similar data points together while keeping dissimilar data points apart. The output for t-SNE is not deterministic, meaning the output won’t exactly be the same every time the algorithm is run. Plotly, for Python, was used to plot the graphs, since it has a highly interactive user interface.

### SNP Annotation
After identifying some populations of humans that clustered closely with the Denisovans, a heatmap was constructed, using Pandas, to try and identify common SNP mutations between them. These SNP mutations were then referenced against dbSNP to try and identify their functional role.

## Reference
Andrews, R. M., Kubacka, I., Chinnery, P. F., Lightowlers, R. N., Turnbull, D. M., & Howell, N. (1999). Reanalysis and revision of the Cambridge reference sequence for human mitochondrial DNA. Nature Genetics, 23(2), 147–147. https://doi.org/10.1038/13779 
Bae, C. J., Douka, K., & Petraglia, M. D. (2017). On the origin of modern humans: Asian perspectives. Science, 358(6368), eaai9067. https://doi.org/10.1126/science.aai9067 

Campbell, M. C., & Tishkoff, S. A. (2008). African Genetic Diversity: Implications for Human Demographic History, Modern Human Origins, and Complex Disease Mapping. Annual Review of Genomics and Human Genetics, 9(1), 403–433. https://doi.org/10.1146/annurev.genom.9.081307.164258 

Gabriel, S. B. (2002). The Structure of Haplotype Blocks in the Human Genome. Science, 296(5576), 2225–2229. https://doi.org/10.1126/science.1069424 

Galtier, N., Gouy, M. and Gautier, C. (1996) SeaView and Phylo_win, two graphic tools for sequence alignment and molecular phylogeny. Comput. Applic. Biosci., 12, 543-548.

Gibbs, R. A., Boerwinkle, E., Doddapaneni, H., Han, Y., Korchina, V., … Rasheed, A. (2015). A global reference for human genetic variation. Nature, 526(7571), 68–74. https://doi.org/10.1038/nature15393

Gupta, A., & Bhardwaj, A. (2013). Mitochondrial DNA- a Tool for Phylogenetic and Biodiversity Search in Equines. Journal of Biodiversity & Endangered Species, 1(s1). https://doi.org/10.4172/2332-2543.s1-006

Johnson, N. (2014). Faculty of 1000 evaluation for The genomic landscape of Neanderthal ancestry in present-day humans. F1000 - Post-publication Peer Review of the Biomedical Literature. doi:10.3410/f.718256977.793494272

Ladoukakis, E. D., & Zouros, E. (2017). Evolution and inheritance of animal mitochondrial DNA: rules and exceptions. Journal of Biological Research-Thessaloniki, 24(1). https://doi.org/10.1186/s40709-017-0060-4 

Li, H., & Durbin, R. (2010). Fast and accurate long-read alignment with Burrows–Wheeler transform. Bioinformatics, 26(5), 589–595. https://doi.org/10.1093/bioinformatics/btp698 

Li, H., Handsaker, B., Wysoker, A., Fennell, T., Ruan, J., … Homer, N. (2009). The Sequence Alignment/Map format and SAMtools. Bioinformatics, 25(16), 2078–2079. https://doi.org/10.1093/bioinformatics/btp352

Pääbo, S., Poinar, H., Serre, D., Jaenicke-Després, V., Hebler, J., Rohland, N., … Hofreiter, M. (2004). Genetic Analyses from Ancient DNA. Annual Review of Genetics, 38(1), 645–679. https://doi.org/10.1146/annurev.genet.37.110801.143214 

Paradis E. & Schliep K. (2018). ape 5.0: an environment for modern phylogenetics and evolutionary analyses in R. Bioinformatics xx: xxx-xxx. 

Pedregosa, F., Varoquaux, G., Gramfort, A., Michel, V., Thirion, B., Grisel, O., Blondel, M., Prettenhofer, P., Weiss, R., Dubourg, V., Vanderplas, J., Passos, A., Cournapeau, D., Brucher, M., Perrot, M., and Duchesnay, E. (2011). Scikit-learn: Machine learning in Python. Journal of Machine Learning Research, 12:2825–2830.

Sankararaman, S., Mallick, S., Patterson, N., & Reich, D. (2016). The Combined Landscape of Denisovan and Neanderthal Ancestry in Present-Day Humans. Current Biology, 26(9), 1241–1247. https://doi.org/10.1016/j.cub.2016.03.037

Sato, M., & Sato, K. (2013). Maternal inheritance of mitochondrial DNA by diverse mechanisms to eliminate paternal mitochondrial DNA. Biochimica et Biophysica Acta (BBA) - Molecular Cell Research, 1833(8), 1979–1984. https://doi.org/10.1016/j.bbamcr.2013.03.010 

Sawyer, S., Renaud, G., Viola, B., Hublin, J.-J., Gansauge, M.-T., Shunkov, M. V., … Pääbo, S. (2015). Nuclear and mitochondrial DNA sequences from two Denisovan individuals. Proceedings of the National Academy of Sciences, 201519905. https://doi.org/10.1073/pnas.1519905112 

Schwartz, M., & Vissing, J. (2002). Paternal Inheritance of Mitochondrial DNA. New England Journal of Medicine,347(8), 576-580. doi:10.1056/nejmoa020350

Sharbrough, J., Havird, J. C., Noe, G. R., Warren, J. M., & Sloan, D. B. (2017). The Mitonuclear Dimension of Neanderthal and Denisovan Ancestry in Modern Human Genomes. Genome Biology and Evolution, 9(6), 1567–1581. https://doi.org/10.1093/gbe/evx114 

Slon, V., Mafessoni, F., Vernot, B., de Filippo, C., Grote, S., Viola, B., … Pääbo, S. (2018). The genome of the offspring of a Neanderthal mother and a Denisovan father. Nature, 561(7721), 113–116. https://doi.org/10.1038/s41586-018-0455-x

Wes M. (2010). Data Structures for Statistical Computing in Python, Proceedings of the 9th Python in Science Conference, 51-56.
Willerslev, E., & Cooper, A. (2005). Review Paper. Ancient DNA. Proceedings of the Royal Society B: Biological Sciences, 272(1558), 3–16. https://doi.org/10.1098/rspb.2004.2813 

Williams, K. P., Sobral, B. W., & Dickerman, A. W. (2007). A Robust Species Tree for the Alphaproteobacteria. Journal of Bacteriology, 189(13), 4578–4586. https://doi.org/10.1128/jb.00269-07 
