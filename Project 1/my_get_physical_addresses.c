#include <linux/kernel.h>
#include <linux/syscalls.h>
#include <linux/sched.h>
#include <asm/pgtable.h>


SYSCALL_DEFINE1(my_get_physical_addresses, unsigned long, virt_addr)
{
	pgd_t *pgd;
	p4d_t *p4d;
	pud_t *pud;
	pmd_t *pmd;
	pte_t *pte;
	unsigned long pfn_addr = 0;
	unsigned long virt_offset = 0;
	unsigned long phy_addr = 0;

	pgd = pgd_offset(current->mm, virt_addr);
	if (pgd_none(*pgd))
		return -1;

        // p4d = (p4d_t *) pgd;
        p4d = p4d_offset(pgd, virt_addr);
        if (p4d_none(*p4d))
                return -1;

        pud = pud_offset(p4d, virt_addr);
	if (pud_none(*pud))
		return -1;

	pmd = pmd_offset(pud, virt_addr);
	if (pmd_none(*pmd))
		return -1;

	pte = pte_offset_kernel(pmd, virt_addr);
	if (pte_none(*pte))
		return -1;

	pfn_addr = pte_val(*pte) & PTE_PFN_MASK & PAGE_MASK;
	virt_offset = virt_addr & ~PAGE_MASK;
	phy_addr = pfn_addr | virt_offset;
	
	
	return phy_addr;
}
